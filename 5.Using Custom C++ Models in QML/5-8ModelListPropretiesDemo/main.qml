import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import com.blikoon.models 1.0

Window {
    visible: true
    width: 400
    height: 600
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("Hello World")

    PersonModel{
        id : mModeId
        Person{
            names: "Steve Barker"
            favoriteColor: "blue"
            age : 34
        }
        Person{
            names: "John Snow"
            favoriteColor: "yellow"
            age : 33
        }
        Person{
            names: "Daniel Gakwaya"
            favoriteColor: "green"
            age : 23
        }

        /*
        persons: [

            Person{
                names: "Daniel Gakwaya"
                favoriteColor: "yellow"
                age : 34
            },
            Person{
                names: "Gwiza Luna"
                favoriteColor: "blue"
                age : 1
            },
            Person{
                names: "Steve Barker"
                favoriteColor: "yellowgreen"
                age : 22
            }

        ]
        */
    }


    ColumnLayout{
        anchors.fill: parent
        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true

            model : mModeId
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
                        mModeId.addPerson(personNames,"yellowgreen",personAge)
                    }
                }


            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    mModeId.removeLastItem()
                }
            }
        }
    }

}
