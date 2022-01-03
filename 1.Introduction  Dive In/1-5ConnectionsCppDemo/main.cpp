#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "cppsignalsender.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CppSignalSender sender;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("CppSignalSender",&sender);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
