#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <singletonclass.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    /*
    qmlRegisterSingletonType("com.blikoon.singletondata",1,0,"MyApi",
                             SingletonClass::singletonProvider);
    */

    qmlRegisterSingletonType("com.blikoon.singletondata",1,0,"MyApi",
                             [](QQmlEngine *engine, QJSEngine *scriptEngine)->QJSValue{
        Q_UNUSED(scriptEngine)
        int mValue = 5;

        QJSValue jsValue = engine->newObject();
        jsValue.setProperty("someProperty",mValue);

        //Put in an array
        QJSValue mArray = engine->newArray(3);
        for (unsigned int i = 1; i <= 3; ++i) {
            mArray.setProperty(i, i*5);
        }

        jsValue.setProperty("mArray",mArray);

        return jsValue;

    });

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
