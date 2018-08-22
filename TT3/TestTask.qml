import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import Mashines 1.0

Frame {
    ListView {
        implicitWidth: 250
        implicitHeight: 300
        clip: true

        model: MashinesModel{}

        delegate: RowLayout {
            width: parent.width
            CheckBox{
                checked : model.del
                onClicked: model.done =checked
            }
            TextField {
                text : model.descriptor
                onEditingFinished: model.descriptor = text
                Layout.fillWidth: true
            }
        }

    }

}
