#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "datasource.h"
#include "personmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PersonModel mModel;
    DataSource * ds = new DataSource(&mModel);
    mModel.setDataSource(ds);

     engine.rootContext()->setContextProperty("myModel",&mModel);
     engine.rootContext()->setContextProperty("myDataSource",ds);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
