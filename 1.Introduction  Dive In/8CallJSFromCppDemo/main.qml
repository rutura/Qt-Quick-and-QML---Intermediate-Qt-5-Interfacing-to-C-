import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Call JS from C++")

    function qmlJSFunction(param){
        console.log(" QML Talking, C++ called me with parameter : "+ param + "returning back something")
        return "This is QML, over to you C++. Thanks for the Call."
    }

    Button {
        id : mButton
        text : "Call QML function from C++"
        onClicked: {
            QmlJsCaller.cppMethod("QML Calling... ")
        }
    }
}
