#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "player.h"
#include "striker.h"
#include "defender.h"
#include "playerdetails.h"
#include "footballteam.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //Register Types
    qmlRegisterType<PlayerDetails>();

    qmlRegisterUncreatableType<Player>("com.blikoon.Football", 1,0, "Player",
                                       "Can not create Player in QML.Not allowed.");

    qmlRegisterType<Striker>("com.blikoon.Football", 1,0, "Striker");
    qmlRegisterType<Defender>("com.blikoon.Football", 1,0, "Defender");
    qmlRegisterType<FootBallTeam>("com.blikoon.Football", 1,0, "FootBallTeam");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
