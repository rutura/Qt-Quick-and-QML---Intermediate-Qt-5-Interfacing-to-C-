import QtQuick 2.12
import QtQuick.Window 2.12
import RandomUtil 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Property Value Sources Demo")

    Rectangle{
        id : mRect
        RandomNumber on width {
            maxValue: 700
        }
        height: 300
        color: "dodgerblue"
        RandomNumber on radius {
            maxValue: 300
        }
    }
}
