import QtQuick 2.12
import QtQuick.Window 2.12
import com.blikoon1.singletondata1 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Singleton QObject Demo")

    Rectangle {
        id : rect1
        width: 200
        height: 200
        radius: 20
        color: "red"

        Text {
            id: mText1
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 30
            text: MyApi.someProperty
        }
    }

    Rectangle {
        id : rect2
        anchors.left : rect1.right
        width: 200
        height: 200
        radius: 20
        color: "blue"

        Text {
            id: mText2
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 30
            text: MyApi.someProperty
        }
    }
}
