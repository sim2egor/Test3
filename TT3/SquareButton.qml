import QtQuick 2.0

Rectangle {
    id: root

    property bool pressed: mouseArea.pressed

    signal buttonClicked(real xPos, real yPos)


    property int side: 20
    width: side; height: side
    //color: "blue"
    Image {
        id: i1
        source: "icons/right.png"
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: root.buttonClicked(mouse.x, mouse.y)
    }
}




