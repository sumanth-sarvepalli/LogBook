import QtQuick
import QtQuick.Window

Window {
    width: screenWidth
    height: screenHeight
    visible: true
    title: qsTr("LogBook")
    color: "black"

    UserLog {
        width: parent.width
        height: parent.height
    }
}
