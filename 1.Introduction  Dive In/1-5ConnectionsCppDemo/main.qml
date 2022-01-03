import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Connections C++ Demo")


    Connections{
        target: CppSignalSender
        onCallQml : {
            console.log("This is QML : callQml signal cought")
            mText.text = parameter;
        }

        onCppTimer: {
            mRectText.text = value;
        }
    }

    Column{
        Rectangle{
            width: 200
            height: 200
            color: "red"
            radius: 20

            Text{
                id : mRectText
                text : "0"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 30
            }
        }

        Button{
            text : "Call C++ Method"
            onClicked: {
                CppSignalSender.cppSlot()
            }

        }

        Text {
            id: mText
            text: qsTr("Default")
        }
    }
}
