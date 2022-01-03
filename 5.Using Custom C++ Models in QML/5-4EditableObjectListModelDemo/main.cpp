#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "objectlistwrapper.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ObjectListWrapper wrapper;

    if(!wrapper.initialize())
        return -1;

    return app.exec();
}
