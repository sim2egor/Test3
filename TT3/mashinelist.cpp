#include "mashinelist.h"
#include "mashinelist.h"
#include "mashinelist.h"
#include "mashinelist.h"
#include <QtSql>

MashineList::MashineList(QObject *parent) : QObject(parent)
{
    QSqlQuery q;
    q.exec(QLatin1String("select * from notes;"));
    bool checked;
    QString note;
    while (q.next()) {
        checked = q.value(1).toBool();
        QString note = q.value(2).toString();
        mItems.append({checked,note});
    }
}

MashineList::~MashineList()
{
    QSqlQuery q;
    q.exec(QLatin1String("delete from notes;"));
    if (!q.prepare(QLatin1String("insert into notes(checked, note) values(?,?)"))){
        qDebug() << q.lastError();
    }
    for(MashineItem item :mItems){
        q.addBindValue(item.del);
        q.addBindValue(item.descriptor);
        if(!q.exec())
            qDebug() << q.lastError();;
    }
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

void MashineList::copydItem(int index)
{
    emit preAppendItem();
    const MashineItem &old = mItems.at(index);
    MashineItem item;
    item.del = old.del;
    item.descriptor=old.descriptor;
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

