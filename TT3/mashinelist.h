#ifndef MASHINELIST_H
#define MASHINELIST_H

#include <QObject>
#include <QVector>

struct MashineItem{
    bool del;
    QString descriptor;
};

class MashineList : public QObject
{
    Q_OBJECT
public:
    explicit MashineList(QObject *parent = nullptr);
    ~MashineList();

    QVector <MashineItem> items() const;
    bool setItemAt(int index,const MashineItem &item);


signals:
    void preAppendItem();
    void postAppendItem();

    void preRemovedItem(int index);
    void postRemovedItem();

public slots:
    void appendItem();
    void removedCompleteItem();
    void copydItem(int index);
private:
    QVector <MashineItem> mItems;
};

#endif // MASHINELIST_H
