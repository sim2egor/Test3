#ifndef SQUAREBUTTON_H
#define SQUAREBUTTON_H

#include <QAbstractItemModel>

class SquareButton : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit SquareButton(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // SQUAREBUTTON_H