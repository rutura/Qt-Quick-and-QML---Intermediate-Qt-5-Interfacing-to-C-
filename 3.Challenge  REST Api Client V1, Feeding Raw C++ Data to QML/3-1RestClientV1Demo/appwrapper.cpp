#include <QNetworkRequest>
#include <QQmlContext>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void AppWrapper::fetchPosts(int number)
{
    //Initialize our API data
    const QUrl API_ENDPOINT("http://api.icndb.com/jokes/random/"+QString::number(number));
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&AppWrapper::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&AppWrapper::dataReadFinished);

}

void AppWrapper::removeLast()
{
    if ( !mJokes.isEmpty()){
        mJokes.removeLast();
        resetModel();
    }
}

QStringList AppWrapper::jokes() const
{
    return mJokes;
}

bool AppWrapper::initialize()
{

    mEngine.rootContext()->setContextProperty("Wrapper",this);
    resetModel();

    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty()){
        return false;
    }else{
        return true;
    }
}

void AppWrapper::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
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

            mJokes.append(joke);
        }

        if(array.size() !=0){
            resetModel();
        }

        //Clear the buffer
        mDataBuffer->clear();
    }
}

void AppWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("myModel",QVariant::fromValue(mJokes));

}
