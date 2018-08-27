#include "squarebutton.h"

SquareButton::SquareButton(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex SquareButton::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex SquareButton::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int SquareButton::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int SquareButton::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SquareButton::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
