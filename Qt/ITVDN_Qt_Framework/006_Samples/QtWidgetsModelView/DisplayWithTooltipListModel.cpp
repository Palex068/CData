#include "DisplayWithTooltipListModel.h"

DisplayWithTooltipListModel::DisplayWithTooltipListModel(QObject* parent)
    : QAbstractListModel(parent)
{
    mDisplayWithTooltipList = { { "Hello", "HelloTooltip" },
        { "World", "WorldTooltip" },
        { "Test", "TestTooltip" } };
}

int DisplayWithTooltipListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return mDisplayWithTooltipList.count();
}

QVariant DisplayWithTooltipListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        return mDisplayWithTooltipList[index.row()].first;
    case Qt::ToolTipRole:
        return mDisplayWithTooltipList[index.row()].second;
    default:
        return QVariant();
    }
}

void DisplayWithTooltipListModel::addDisplayWithTooltip(QPair<QString, QString> displayWithTooltop)
{
    auto index = rowCount();
    beginInsertRows(QModelIndex(), index, index);
    mDisplayWithTooltipList.push_back(displayWithTooltop);
    endInsertRows();
}
