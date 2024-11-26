import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12
import "MyComponents"
import "UsefulFunctions.js" as UsefulFunctions

ApplicationWindow {
    id: applicationWindow

    property string someString
    property var someBool: true
    readonly property int someNumber: 10

    property list<Rectangle> rects: [
        Rectangle { color: "red" },
        Rectangle { color: "blue"}
    ]

    property alias myRectColor: myRect.color
    signal mouseAreaClicked(var clickX, var clickY)

    title: UsefulFunctions.returnSomething()
    width: 900
    visible: true

    MyRect {
        id: myRect
        color: 'black'
    }

    MyRectInFolder {
        id: myRectInFolder
        x: 100
        y: parent.width == 900 ? 100 : 200
    }

    Binding {
        target: applicationWindow
        property: "height"
        value: 800
    }

    onMouseAreaClicked: {
        console.debug("onMouseAreaClicked ", clickX, " ", clickY)
        if (clickX > 100) {
            console.debug("clickX > 100")
        }
        console.debug("myRectColor", myRectColor)
    }

    Connections {
        target: myRectInFolder
        onColorChanged: console.debug("myRectInFolder onColorChanged ", myRectInFolder.color)
    }

    Component.onCompleted: console.debug("Fibonacci 20 ", fibonacci(20));

    function fibonacci(n){
        var arr = [0, 1];
        for (var i = 2; i < n + 1; i++)
            arr.push(arr[i - 2] + arr[i -1]);

        return arr;
    }
}
