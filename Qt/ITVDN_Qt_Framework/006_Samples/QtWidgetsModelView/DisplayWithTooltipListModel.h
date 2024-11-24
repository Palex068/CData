#ifndef DISPLAYWITHTOOLTIPLISTMODEL_H
#define DISPLAYWITHTOOLTIPLISTMODEL_H

#include <QAbstractListModel>

class DisplayWithTooltipListModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit DisplayWithTooltipListModel(QObject* parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

public:
    void addDisplayWithTooltip(QPair<QString, QString> displayWithTooltop);

private:
    QList<QPair<QString, QString>> mDisplayWithTooltipList;
};

#endif // DISPLAYWITHTOOLTIPLISTMODEL_H
