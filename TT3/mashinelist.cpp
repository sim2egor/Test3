#include "mashinelist.h"

MashineList::MashineList(QObject *parent) : QObject(parent)
{
    mItems.append({false,QStringLiteral("----1---")});
    mItems.append({false,QStringLiteral("----2---")});
}

QVector <MashineItem> MashineList::items() const
{
    return mItems;

}

bool MashineList::setItemAt(int index, const MashineItem &item)
{
    if(index <0 || index >= mItems.size())
        return false;
    const MashineItem &old = mItems.at(index);
    if(item.del == old.del && item.descriptor == old.descriptor)
        return false;
    mItems[index] = item;
    return true;

}

void MashineList::appendItem()
{
    emit preAppendItem();

    MashineItem item;
    item.del = false;
    mItems.append(item);
    emit postAppendItem();
}

void MashineList::removedCompleteItem()
{
    MashineItem item;
    for (int i=0; i< mItems.size();)
    {
        item = mItems.at(i);
        if (mItems.at(i).del) {
            emit preRemovedItem(i);
            mItems.remove(i);
            emit postRemovedItem();
        }
        else {
            ++i;
        }
    }
}
