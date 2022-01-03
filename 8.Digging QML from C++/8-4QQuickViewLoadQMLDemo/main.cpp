#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QQuickItem>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    QObject * rootObject = view.rootObject();
    qDebug() << "Root object name is : " << rootObject->objectName();

    QObject * object = rootObject->findChild<QObject*>("rect");
    if( object){
        QQuickItem * item = qobject_cast<QQuickItem*>(object);

        //Modify its properties
        QColor color(Qt::blue);
        item->setProperty("color",color);
        item->setProperty("width",QVariant::fromValue(600));
        item->setProperty("height",QVariant::fromValue(600));
    }


    return app.exec();
}
