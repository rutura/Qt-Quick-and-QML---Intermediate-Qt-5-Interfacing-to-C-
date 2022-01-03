#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject * rootObject = engine.rootObjects()[0];

    QObject * funcContext = rootObject->findChild<QObject*>("deep2");

    if( funcContext){
        qDebug() << "Found the object";
        QVariant returnValue;
        QVariant parameter = "C++ Parameter";

        QMetaObject::invokeMethod(funcContext,"qmlFunction",
                                  Q_RETURN_ARG(QVariant,returnValue),
                                  Q_ARG(QVariant,parameter)
                                  );
        qDebug() << "This is C++, return value is : " << returnValue.toString();

    }



    return app.exec();
}
