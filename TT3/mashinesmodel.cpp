#include "mashinesmodel.h"

#include "mashinelist.h"

MashinesModel::MashinesModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int MashinesModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 100;
}

QVariant MashinesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    switch (role) {
    case DelRole :
        return QVariant(false);
    case DescriptorRole:
        return QVariant(QStringLiteral(" Test Test"));

    }
    return QVariant();
}

bool MashinesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags MashinesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> MashinesModel::roleNames() const
{
    QHash <int, QByteArray> names;
    names[DelRole] ="del";
    names[DescriptorRole] = "descriptor";
    return names;
}

MashineList *MashinesModel::list() const
{
    return mList;
}

void MashinesModel::setList(MashineList *list)
{
    beginResetModel();

    if(mList){
        mList->disconnect(this);
    }
    mList = list;
//    if(mList){
//        connect(mList,&MashineList::preAppendItem,this,[=]() {
//            const int index = mList->items().size();
//            beginInsertRows(QModelIndex(),index,index);
//        });
//        connect(mList,&MashineList::postAppendItem,this,[=]() {
            endInsertRows();
        });
        connect(mList,&MashineList::preRemovedItem,this,[=](int index) {
            beginRemoveRows(QModelIndex(),index,index);
        });
        connect(mList,&MashineList::postRemovedItem,this,[=]() {
            endRemoveRows();
        });

    }
    endResetModel();
}
