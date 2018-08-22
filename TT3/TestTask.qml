import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Frame {
    ListView {
        implicitWidth: 250
        implicitHeight: 300


        model: 100
        delegate: RowLayout {
            CheckBox{}
            TextField {}
        }

    }

}
