import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
	id: window

    property double lat: 48.866667
    property double lon: 2.333333
	// property Component locationMarker: maker

	Plugin {
		id: googleMapView
		name: "osm"
	}

	Map {
		id: mapView
		anchors.fill: parent
		plugin: googleMapView
		center: QtPositioning.coordinate(lat, lon)
		zoomLevel: 15
	}
}

