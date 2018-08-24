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
    if (parent.isValid()|| !(mList))
        return 0;


    return mList->items().size();
}

QVariant MashinesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !(mList))
        return QVariant();

    const MashineItem item = mList->items().at(index.row());
    switch (role) {
    case DelRole :
        return QVariant(item.del);
    case DescriptorRole:
        return QVariant(item.descriptor);

    }
    return QVariant();
}

bool MashinesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList) {
        return false;
    }
    MashineItem item = mList->items().at(index.row());
    switch (role) {
    case DelRole :
     item.del = value.toBool();
        break;
    case DescriptorRole:
        item.descriptor = value.toString();
        break;
    }
    if (mList->setItemAt(index.row(),item)) {
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
  if(mList){
        connect(mList,&MashineList::preAppendItem,this,[=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });
        connect(mList,&MashineList::postAppendItem,this,[=]() {
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
