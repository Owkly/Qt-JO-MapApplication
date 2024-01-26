// MarkerLocation.qml
import QtQuick 2.0

Item {
    property string markerId: ""

    width: 30
    height: 30

    Image {
        id: image
        source: "images/markerLocation.png"
        anchors.fill: parent
    }

    Rectangle {
        id: tooltipBackground
        color: "white"
        radius: 5
        visible: false
        width: tooltip.width
        height: tooltip.height

        Text {
            id: tooltip
            text: markerId
            color: "black"
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            tooltipBackground.visible = true
        }
        onExited: {
            tooltipBackground.visible = false
        }
    }
}
