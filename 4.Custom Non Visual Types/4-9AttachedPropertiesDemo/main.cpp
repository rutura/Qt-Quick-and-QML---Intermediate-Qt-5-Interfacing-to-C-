#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "timerattached.h"
#include "timer.h"
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<TimerAttached>();//Can not create instances
    qmlRegisterType<Timer>("Timing",1,0,"Timer");


    qmlRegisterType<Person>("People", 1,0, "Person");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
