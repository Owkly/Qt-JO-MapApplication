// MarkerRectangle.qml
import QtQuick 2.0

Item {
    property string markerId: ""

    width: 30
    height: 30

    Image {
        id: image
        source: "images/markerRestaurant.png"
        anchors.fill: parent
    }

    Rectangle {
        id: tooltipBackground
        radius: 5
        visible: false
        width: tooltip.width
        height: tooltip.height

        Text {
            id: tooltip
            text: markerId
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
