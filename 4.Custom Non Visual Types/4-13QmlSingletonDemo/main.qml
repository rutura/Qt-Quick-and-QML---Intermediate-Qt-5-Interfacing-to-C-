import QtQuick 2.12
import QtQuick.Window 2.12
import com.blikoon.qmlsingleton 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Singleton QML Demo")

    Component.onCompleted: {
        console.log(QMLSingleton.testProperty)
    }
}
