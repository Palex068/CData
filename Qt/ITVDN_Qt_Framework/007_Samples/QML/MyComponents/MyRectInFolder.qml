import QtQuick 2.0

Rectangle {
    property color nextColor: "#1fc974"

    width: 200
    height: 100
    color: nextColor
    border.color: "#e21d1d"

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            parent.color = (parent.color == '#f1ff00') ? parent.nextColor : '#f1ff00'
        }
    }
}


