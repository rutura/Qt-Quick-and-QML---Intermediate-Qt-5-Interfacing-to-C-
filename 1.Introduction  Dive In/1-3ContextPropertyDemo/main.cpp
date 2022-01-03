#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "cppworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CppWorker worker;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("BWorker",&worker);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
