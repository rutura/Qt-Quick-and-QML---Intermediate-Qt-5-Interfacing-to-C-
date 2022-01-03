#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "qmljscaller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QmlJSCaller jsCaller;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("QmlJsCaller",&jsCaller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()){
       return -1;
    }else{
        //Should make sure this is SET
        jsCaller.setQmlRootObject(engine.rootObjects().first());
    }


    return app.exec();
}
