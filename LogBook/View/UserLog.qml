import QtQuick
import QtQuick.Controls

Rectangle {
    color: "black"

    Button{
        id: logButton
        width: 100
        height: 100
        padding: 4
        anchors.centerIn: parent
        background: Rectangle{
            color: parent.hovered ? "#686891" : "#d6e0df"
            radius: 10
        }

        Image {
            id: userLogImage
            anchors{
                top: parent.top
                topMargin: 5
                horizontalCenter: parent.horizontalCenter
            }
            source: "qrc:/LogBook/Images/logbook.svg"
            sourceSize.width: 60
            sourceSize.height: 60
        }

        Text{
            id: btnTxt
            anchors {
                bottom: parent.bottom
                bottomMargin: 10
                horizontalCenter: parent.horizontalCenter
            }
            text: qsTr("User Log")
            font.pointSize: 12
            elide: Text.ElideRight
        }
        onClicked: {
            pageLoader.source = "LogBook.qml"
        }
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
    }
}
