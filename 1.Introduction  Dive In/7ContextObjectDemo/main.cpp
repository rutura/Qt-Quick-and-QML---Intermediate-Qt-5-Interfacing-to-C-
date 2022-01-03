#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "propertywrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    /*
    QString lastName = "Doe";
    QString firstName = "John";
    */

    PropertyWrapper propWrapper;
    propWrapper.setLastname("Doe");
    propWrapper.setFirstname("John");

    QQmlApplicationEngine engine;


    /*
    engine.rootContext()->setContextProperty("mLastname",QVariant::fromValue(lastName));
    engine.rootContext()->setContextProperty("mFirstname",QVariant::fromValue(firstName));
    */
    engine.rootContext()->setContextObject(&propWrapper);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
