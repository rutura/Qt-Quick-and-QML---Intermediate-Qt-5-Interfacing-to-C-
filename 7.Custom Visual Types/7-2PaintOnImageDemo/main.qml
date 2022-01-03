import QtQuick 2.12
import QtQuick.Window 2.12
import com.blikoon.logos 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Logo{
        id : mLogo1
        text: "Learn QT"
        bgColor: "blue"
        textColor: "red"
    }

    Logo{
        id : mLogo2
        anchors.top : mLogo1.bottom
        anchors.topMargin: 20
        text: "Go Fluid"
        bgColor: "beige"
        textColor: "black"
        topic: Logo.QTQUICK
    }
}
