#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <player.h>
#include <footballteam.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Register Types
    qmlRegisterType<Player>("com.blikoon.Football", 1,0, "Player");
    qmlRegisterType<FootBallTeam>("com.blikoon.Football", 1,0, "FootballTeam");

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/main.qml"));

    FootBallTeam * team = qobject_cast<FootBallTeam* > (component.create());

    if(team && team->captain()){
        qDebug() << "Team : " << team->title() << " , captain is : " << team->captain()->name();
        qDebug() << "The players are : ";

        for ( int ix = 1; ix < team->playerCountCustom() ; ix++){
            qDebug() << " " << team->playerCustom(ix)->name();
        }

    }

    return a.exec();
}
