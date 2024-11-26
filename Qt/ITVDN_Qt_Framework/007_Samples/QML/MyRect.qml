import QtQuick 2.0

Rectangle {
    property color nextColor: "blue"

    x: parent.width / 2
    y: parent.height / 2
    width: parent.width / 4
    height: parent.height / 4

    color: nextColor

    onWidthChanged:
    {
        var widthPlusHeigh = width + height
        console.debug("rect width + height =", widthPlusHeigh )
    }

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            parent.color = (parent.color == '#ff0000') ? parent.nextColor : '#ff0000'
            console.debug("rect color=", parent.color)
            applicationWindow.mouseAreaClicked(mouseX, mouseY);
        }
    }
}
