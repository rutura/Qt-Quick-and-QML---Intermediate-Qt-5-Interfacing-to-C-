import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView{
        id : mListView
        anchors.fill: parent
        model : Wrapper.mypersons
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
                    //text : names
                    text : modelData.names
                    Layout.fillWidth: true
                    onEditingFinished: {
                        Wrapper.setNames(index,text)
                    }
                }
                SpinBox{
                    editable: true
                    //value : age //
                    value : modelData.age
                    Layout.fillWidth: true
                    onValueChanged: {
                        if( value === model.age){

                        }else{
                            Wrapper.setAge(index,value)
                        }
                    }
                }
                Rectangle{
                    width : 50
                    height: 50
                    color: modelData.favoriteColor // This format only works for model defined in qml like our mModelId here. // color : model.modelData.favoriteColor// Can also do modelData.favoriteColor directly but adding model makes it clear where the data is coming from. More readable
                }
            }
        }
    }

    Button{
        id : mButton
        width: parent.width
        anchors.bottom: parent.bottom
        height: 50
        text : "Add Person"
        onClicked: {
            Wrapper.addPerson()
        }
    }
}
