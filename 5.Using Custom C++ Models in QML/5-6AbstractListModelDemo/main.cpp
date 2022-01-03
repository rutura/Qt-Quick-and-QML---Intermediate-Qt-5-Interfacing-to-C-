#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "personmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    PersonModel mModel;

    QQmlApplicationEngine engine;

     engine.rootContext()->setContextProperty("myModel",&mModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
