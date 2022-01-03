#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "player.h"
#include "footballteam.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //Register Types
    qmlRegisterType<Player>("com.blikoon.Football", 1,0, "Player");
    qmlRegisterType<FootBallTeam>("com.blikoon.Football", 1,0, "FootBallTeam");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
