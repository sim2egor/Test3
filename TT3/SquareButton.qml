import QtQuick 2.0

Rectangle {
    id: root

    property bool pressed: mouseArea.pressed

    signal buttonClicked(real xPos, real yPos)

    function randomizeColor() {
        root.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
    }

    property int side: 20
    width: side; height: side
    color: "blue"

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: root.buttonClicked(mouse.x, mouse.y)
    }
}




