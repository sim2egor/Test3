import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import Mashines 1.0


ColumnLayout {
    Frame {
        Layout.fillWidth: true
        ListView {
            implicitWidth: 250
            implicitHeight: 300
            clip: true
            anchors.fill: parent

            model: MashinesModel{
                list: mashList
            }

            delegate: RowLayout {
                width: parent.width
                CheckBox{
                    checked : model.del
                    onClicked: model.del =checked
                }
                TextField {
                    text : model.descriptor
                    onEditingFinished: model.descriptor = text
                    Layout.fillWidth: true
                }
            }

        }

    }
    RowLayout{
        Button {
            text: qsTr("add")
            Layout.fillWidth: true
            onClicked: mashList.appendItem();
        }
        Button {
            text: qsTr("delet")
            Layout.fillWidth: true
            onClicked: mashList.removedCompleteItem();
        }
    }
}
