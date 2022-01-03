import QtQuick 2.12
import QtQuick.Window 2.12
import com.blikoon.Football 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    FootBallTeam {
        id : team1
        title: "Rayon Sports"
        coatch: "Coatch Name"
        captain: Player{
            name: "Captain"
            position: "Middle Field"
            playing: true
        }

        players: [

            Player{
                name: "Player1"
                position: "Middle Field"
                playing: true
            },
            Player{
                name: "Player2"
                position: "Middle Field"
                playing: true
            },
            Player{
                name: "Player3"
                position: "Middle Field"
                playing: true
            },
            Player{
                name : "Daniel"
                position: "None"
                playing: false
            }



        ]
    }

    ListView {
        anchors.fill: parent
        model : team1.players
        delegate: Rectangle{
            width: parent.width
            height: 50
            border.width: 1
            border.color: "yellowgreen"
            color: "beige"

            Text {
                anchors.centerIn: parent
                text : name
                font.pointSize: 20
            }
        }
    }






    Component.onCompleted: {
        console.log("We have :" + team1.players.length + " players in the team "+ team1.title)
    }
}
