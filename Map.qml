// Map.qml
import QtQuick 2.15
import "."

Rectangle {
    // Image de la carte
    Image {
        id: mapImage
        source: "images/paris.png"
        anchors.fill: parent
    
    // Marqueurs Lieux d'épreuves
        // Stade de France
        MarkerLocation {
            id: stadeDeFrance
            markerId: "Stade de France"
            x: 1000
            y: 50
        }

        // Hippodrome de Longchamp
        MarkerLocation {
            id : hippodromeDeLongchamp
            markerId: "Hippodrome de Longchamp"
            x: 10
            y: 380
        }

        // Parc des Expositions
        MarkerLocation {
            id: parcDesExpositions
            markerId: "Parc des Expositions"
            x: 360
            y: 710
        }

        // Palais des Sports
        MarkerLocation {
            id: palaisDesSports
            markerId: "Palais des Sports"
            x: 350
            y: 730
        }

        // Vélodrome 
        MarkerLocation {
            id: velodrome
            markerId: "Vélodrome"
            x: 600
            y: 250
        }

        // Gymase de buffault
        MarkerLocation {
            id: gymaseDeBuffault
            markerId: "Gymase de Buffault"
            x: 1100
            y: 200   
        }

        // Grand Palais
        MarkerLocation {
            id: grandPalais
            markerId: "Grand Palais"
            x: 700
            y: 400
        }

        // Piscine Suzanne Berlioux
        MarkerLocation {
            id: piscineSuzanneBerlioux
            markerId: "Piscine Suzanne Berlioux"
            x: 1080
            y: 470   
        }

        // Bercy Arena
        MarkerLocation {
            id: bercyArena
            markerId: "Bercy Arena"
            x: 1400
            y: 630
        }

    // Marqueurs pour les restaurants
        // chinois
        MarkerRestaurant {
            id: chinois
            markerId: "Dragon d'Or"
            x: 1050
            y: 100
        }
        
        // Mexicain
        MarkerRestaurant {
            id: mexicain
            markerId: "Azteca Mexicano"
            x: 750
            y: 220
        }

        // Français
        MarkerRestaurant {
            id: francais
            markerId: "Le Gourmet Parisien"
            x: 900
            y: 410
        }

        // Grec
        MarkerRestaurant {
            id: grec
            markerId: "Athènes Grill"
            x: 1020
            y: 310
        }

        // Italien
        MarkerRestaurant {
            id: italien
            markerId: "Roma Pasta"
            x: 200
            y: 600
        }

        // Coréen
        MarkerRestaurant {
            id: coreen
            markerId: "Séoul Gourmet"
            x: 350
            y: 450
        }

        // Japonais
        MarkerRestaurant {
            id: japonais
            markerId: "Tokyo Sushi"
            x: 1610
            y: 450
        }

        // Indien
        MarkerRestaurant {
            id: indien
            markerId: "Dehli Délices"
            x: 1500
            y: 650
        }


    }
}
