#include <QNetworkRequest>
#include <QQmlContext>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent)
{

}
bool AppWrapper::initialize()
{
    DataSource * ds = new DataSource(this);
    mJokeModel.setDatasource(ds);
    mEngine.rootContext()->setContextProperty("myModel",&mJokeModel);
    mEngine.rootContext()->setContextProperty("myDatasource",ds);
    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty()){
        return false;
    }else{
        return true;
    }
}

