import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Object List Model Demo")


    ListView{
        id : mListView
        anchors.fill: parent
        model : personModel
        delegate: Rectangle {
            height: 90
            radius: 10
            color : "gray"// Can also do modelData.favoriteColor directly but adding model makes it clear where the data is coming from. More readable
            border.color: "cyan"
            width: parent.width
            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    text : names
                    //text : modelData.names
                    Layout.fillWidth: true
                }
                SpinBox{
                    editable: true
                    value : age //value : modelData.age
                    Layout.fillWidth: true
                }
                Rectangle{
                    width : 50
                    height: 50
                    color: favoriteColor // This format only works for model defined in qml like our mModelId here. // color : model.modelData.favoriteColor// Can also do modelData.favoriteColor directly but adding model makes it clear where the data is coming from. More readable
                }
            }
        }
    }

    ListModel{
        id : mModelId
        ListElement {
            names : "Daniel Sten"; favoriteColor : "blue"; age : 10
        }
        ListElement {
            names : "Stevie Wongers"; favoriteColor : "cyan"; age : 23
        }
        ListElement {
            names : "Nicholai Ven"; favoriteColor : "red"; age : 33
        }
        ListElement {
            names : "William Glen"; favoriteColor : "yellowgreen"; age : 45
        }
    }


}
