#include "LogBookSortProxyModel.h"
#include "LogBookModel.h"
#include <QDateTime>

LogBookSortProxyModel::LogBookSortProxyModel(QObject *parent)
    :QSortFilterProxyModel(parent)
{
    setSourceModel(LogBookModel::getInstance());
    setSortRole(Qt::DisplayRole);
    sort(0, Qt::DescendingOrder);
}

LogBookSortProxyModel *LogBookSortProxyModel::getInstance()
{
    static LogBookSortProxyModel logBookSortProxyModelobj;
    return &logBookSortProxyModelobj;
}

bool LogBookSortProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    QStringList parts = {};
    QString datetime = "";

    // leftLog
    QString leftLog = sourceModel()->data(source_left).toString();
    parts = leftLog.split(" ");
    datetime = parts.at(1);

    QDateTime leftTime = QDateTime::fromString(datetime, Qt::ISODate);

    // rightLog
    QString rightLog = sourceModel()->data(source_right).toString();
    parts = rightLog.split(" ");
    datetime = parts.at(1);

    QDateTime rightTime = QDateTime::fromString(datetime, Qt::ISODate);

    return leftTime < rightTime; // Descending order
}
