import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3

Window {
    visible: true
    width: 400
    height: 600
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("Hello World")


    ColumnLayout{
        anchors.fill: parent
        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true

            model : myModel
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
                        Layout.fillWidth: true
                        onEditingFinished: {
                            console.log("Editing finished, new text is :"+ text + " at index :" + index)
                            model.names = text //The roles here are defined in model class

                        }
                    }

                    SpinBox{
                        id : mSpinbox
                        editable: true
                        Layout.fillWidth: true
                        onValueChanged: {
                            model.age = value;
                        }
                        Component.onCompleted: {
                            mSpinbox.value = model.age
                        }
                    }
                    Rectangle{
                        width : 50
                        height: 50
                        color: model.favoriteColor
                        MouseArea{
                            anchors.fill: parent
                            ColorDialog{
                                id: colorDialog
                                title: "Please choose a color"
                                onAccepted: {
                                    console.log("You chose: " + colorDialog.color)
                                    model.favoriteColor = color
                                }
                                onRejected: {
                                    console.log("Canceled")

                                }
                            }

                            onClicked: {
                                colorDialog.open()

                            }
                        }
                    }
                }
            }
        }

        RowLayout{
            width : parent.width

            Button{
                Layout.fillWidth: true
                height: 50
                text : "Add Person";
                onClicked: {
                    input.openDialog()
                }
                InputDialog{
                    id : input
                    onInputDialogAccepted: {
                        console.log("Here in main, dialog accepted");
                        console.log( " names : " + personNames + " age :" + personAge)
                        myDataSource.addPerson(personNames,personAge)
                    }
                }


            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    myDataSource.removeLastPerson()
                }
            }
        }
    }

}
