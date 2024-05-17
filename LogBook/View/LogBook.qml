import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    width: screenWidth
    height: screenHeight
    visible: true
    color: "black"

    // Heading Text
    Text {
        id: headingTxt
        text: qsTr("LogBook")
        color: "White"
        font.pointSize: 48
    }

    // Table Header
    Rectangle{
        id: logRect
        width: screenWidth * 0.8
        height: screenHeight * 0.6
        radius: 5
        anchors{
            left: parent.left
            leftMargin: 100
            top: headingTxt.bottom
            topMargin: 20
        }
        color: "white"

        // Heading Row
        Row{
            id: headerRow
            visible: true
            anchors{
                top: logRect.top
                topMargin: 20
                left: logRect.left
                leftMargin: 20
            }
            spacing: 30

            // Id
            Rectangle{
                id: idHeader
                width: 90
                height: 30
                Text {
                    id: idTxt
                    anchors{
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 5
                    }

                    text: qsTr("Id")
                    font.bold: true
                    font.pointSize: 24
                }
            }

            // Date
            Rectangle{
                id: dateHeader
                width: 80
                height: 30
                Text {
                    id: dateTxt
                    anchors{
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 5
                    }

                    text: qsTr("Date")
                    font.bold: true
                    font.pointSize: 24
                }
            }

            // Time
            Rectangle{
                id: timeHeader
                width: 120
                height: 30
                Text {
                    id: timeTxt
                    anchors{
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 5
                    }

                    text: qsTr("Time")
                    font.bold: true
                    font.pointSize: 24
                }
            }

            // Message
            Rectangle{
                id: msgHeader
                width: 60
                height: 30
                Text {
                    id: msgTxt
                    anchors{
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 5
                    }

                    text: qsTr("Message")
                    font.bold: true
                    font.pointSize: 24
                }
            }
        }

        // Heading Row Line Separator
        Rectangle {
            id: lineRect
            height: 5
            width: 900
            color: "black"
            anchors {
                left: parent.left
                leftMargin: 10
                top: headerRow.bottom
                topMargin: 10
            }
        }

        // TableView with Data
        TableView {
            id: logTable
            width: parent.width
            height: parent.height
            clip: true
            columnSpacing: 30
            anchors {
                left: parent.left
                leftMargin: 1
                top: lineRect.bottom
                topMargin: 20
                bottom: parent.bottom
                bottomMargin: 20
            }
            ScrollBar.horizontal: ScrollBar{
                id: hScroll
                hoverEnabled: true
                active: hovered || pressed
                orientation: Qt.Horizontal
                policy: ScrollBar.AsNeeded
                size: 5
            }
            ScrollBar.vertical: ScrollBar{
                id: vScroll
                hoverEnabled: true
                active: hovered || pressed
                orientation: Qt.Vertical
                policy: ScrollBar.AsNeeded
                size: 5
            }
            model: logBookProxyModel
            delegate: Rectangle {
                id: delegateRect
                implicitHeight: 20
                implicitWidth: 100

                Text {
                    id: dispText
                    anchors.fill: parent
                    text: qsTr(displayData())
                    font.pointSize: 12
                }

                function displayData()
                {
                    switch(column){
                    case 0:
                        dispText.text = id;
                        break;
                    case 1:
                        dispText.text = sDate;
                        break;
                    case 2:
                        dispText.text = sTime;
                        break;
                    case 3:
                        dispText.text = sMessage;
                        break;
                    }
                }
            }
        }

    }

    // back Button
    Button {
        id: backBtn
        width: 120
        height: 50
        padding: 4
        anchors{
            bottom: parent.bottom
            right: parent.right
            margins: 40
        }
        background: Rectangle {
            color: parent.hovered ? "#686891" : "#d6e0df"
            radius: 5
        }
        Text {
            id: btnTxt
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                margins: 10
            }

            text: qsTr("Back")
            font.pointSize: 12
            elide: Text.ElideRight
        }
        onClicked: pageLoader.source = "UserLog.qml"
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
    }
}
