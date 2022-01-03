import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Connections QML Demo")

    Row{
        Rectangle{
            id : redRect
            width: 100
            height: 100
            color: "red"

            MouseArea{
                id : redRectMouseAreaId
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked in the red rectangle")
                }
            }
        }

        Rectangle{
            id : greenRect
            width: 100
            height: 100
            color: "green"

            Connections{
                target: redRectMouseAreaId
                onClicked : {
                    console.log("This is green rect responding")
                }
            }


        }

        Rectangle{
            id : blueRect
            width: 100
            height: 100
            color: "blue"

            Connections{
                target: redRectMouseAreaId
                onClicked : {
                    console.log("This is blue rect responding")
                }

            }


        }
    }
}
