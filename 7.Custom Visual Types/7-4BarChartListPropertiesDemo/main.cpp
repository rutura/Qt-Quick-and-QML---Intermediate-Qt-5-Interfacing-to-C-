#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "stair.h"
#include "stairchart.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<StairChart>("com.blikoon.charts",1,0,"StairChart");
    qmlRegisterType<Stair>("com.blikoon.charts",1,0,"Stair");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
