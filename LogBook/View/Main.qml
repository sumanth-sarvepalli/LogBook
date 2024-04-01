import QtQuick
import QtQuick.Window

Window {
    width: 1200
    height: 800
    visible: true
    title: qsTr("LogBook")
    color: "black"

    UserLog {
        width: parent.width
        height: parent.height
    }
}
