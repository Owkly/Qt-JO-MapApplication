import QtQuick 2.0

Item {
    property string markerId: "" // Ajouter une propriété personnalisée

    width: 30
    height: 30

    Image {
        id: image
        source: "images/markerRestaurant.png"
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
            text: markerId // Utiliser la propriété personnalisée
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
