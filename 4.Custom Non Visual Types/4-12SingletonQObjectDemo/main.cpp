#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "singletonclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    /*
    qmlRegisterSingletonType<SingletonClass>("com.blikoon1.singletondata1", 1, 0, "MyApi",
                                                 SingletonClass::singletonProvider);
                                                 */

    qmlRegisterSingletonType<SingletonClass>("com.blikoon1.singletondata1", 1, 0, "MyApi",
                                             [](QQmlEngine *engine, QJSEngine *scriptEngine)->QObject *{
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        SingletonClass * example = new SingletonClass();
        return example;
    });

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
