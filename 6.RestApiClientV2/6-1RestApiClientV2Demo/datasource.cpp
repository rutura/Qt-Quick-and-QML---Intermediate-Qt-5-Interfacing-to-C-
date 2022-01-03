#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "datasource.h"

DataSource::DataSource(QObject *parent) : QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void DataSource::fetchJokes(int number)
{
    //Initialize our API data
    const QUrl API_ENDPOINT("http://api.icndb.com/jokes/random/"+QString::number(number));
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&DataSource::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&DataSource::dataReadFinished);
}

void DataSource::addJoke(Joke *joke)
{
    emit preItemAdded();
    mJokes.append(joke);
    emit postItemAdded();
}

void DataSource::addJoke()
{
    Joke *joke = new Joke("Test Joke Added First",this);
    addJoke(joke);
}

void DataSource::addJoke(const QString &jokeParam)
{
    Joke *joke = new Joke(jokeParam,this);
    addJoke(joke);
}

void DataSource::removeJoke(int index)
{
    emit preItemRemoved(index);
    mJokes.removeAt(index);
    emit postItemRemoved();
}

void DataSource::removeLastJoke()
{
    if ( !mJokes.isEmpty()){
        removeJoke(mJokes.size()-1);
    }
}

QList<Joke *> DataSource::dataItems()
{
    return mJokes;
}

void DataSource::dataReadyRead()
{
     mDataBuffer->append(mNetReply->readAll());
}

void DataSource::dataReadFinished()
{
    //Parse the JSON
    if( mNetReply->error()){
        qDebug() << "There was some error : " << mNetReply->errorString();
    }else{
        //
        //Turn the data into a json document
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
        //Grab the value array
        QJsonObject data = doc.object();

        QJsonArray array = data["value"].toArray();

        qDebug() << "Number of jokes " << array.size();

        for ( int i = 0; i < array.size() ; i++){

            QJsonObject object = array.at(i).toObject();

            QString joke = object["joke"].toString();

            addJoke(joke);
        }

        //Clear the buffer
        mDataBuffer->clear();
    }
}
