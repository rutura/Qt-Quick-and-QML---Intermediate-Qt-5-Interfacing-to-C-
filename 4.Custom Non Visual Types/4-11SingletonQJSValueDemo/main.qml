import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import com.blikoon.singletondata 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Singleton QJSValue Demo")

    Button{
        id : mButton
        text : "Click Me"
        onClicked: {
            console.log(MyApi.someProperty);
            //console.log(MyApi.mArray[0])
            MyApi.mArray.forEach(function(element){
                console.log(element)
            })
        }
    }
    Button{
        id : mButton2
        anchors.top: mButton.bottom
        text : "Click Me2"
        onClicked: {
            console.log(MyApi.someProperty);
            //console.log(MyApi.mArray[0])
            MyApi.mArray.forEach(function(element){
                console.log(element)
            })
        }
    }
}
