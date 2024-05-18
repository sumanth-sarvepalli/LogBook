#include "LogBookProxyModel.h"
#include "LogBookSortProxyModel.h"
#include "LogBookModel.h"
#include <QDateTime>

LogBookProxyModel::LogBookProxyModel(QObject *parent)
    : QAbstractProxyModel(parent)
{
    setSourceModel(LogBookSortProxyModel::getInstance());
}

LogBookProxyModel *LogBookProxyModel::getInstance()
{
    static LogBookProxyModel logBookProxyModelObj;
    return &logBookProxyModelObj;
}

QModelIndex LogBookProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!sourceModel() || parent.isValid())
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex LogBookProxyModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int LogBookProxyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return sourceModel() ? sourceModel()->rowCount() : 0;
}

int LogBookProxyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return sourceModel()->columnCount();
}

QVariant LogBookProxyModel::data(const QModelIndex &index, int role) const
{
    if (!sourceModel() || !index.isValid())
        return QVariant();

    QModelIndex sourceIndex = mapToSource(index);
    QString logEntry = sourceModel()->data(sourceIndex, Qt::DisplayRole).toString();

    QStringList parts = logEntry.split(" ");
    QString id = parts.at(0);
    QString datetime = parts.at(1);
    QDateTime timestamp = QDateTime::fromString(datetime, Qt::ISODate);

    QStringList msgParts = logEntry.split("- ");
    QString logMessage = msgParts.at(1);

    switch (role) {
    case IdRole:
        return id.toInt();
    case DateRole:
        return timestamp.date().toString();
    case TimeRole:
        return timestamp.time().toString();
    case MessageRole:
        return logMessage;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> LogBookProxyModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DateRole] = "sDate";
    roles[TimeRole] = "sTime";
    roles[MessageRole] = "sMessage";
    return roles;
}

QModelIndex LogBookProxyModel::mapToSource(const QModelIndex &proxyIndex) const
{
    if (!proxyIndex.isValid())
        return QModelIndex();

    return sourceModel()->index(proxyIndex.row(), 0);
}

QModelIndex LogBookProxyModel::mapFromSource(const QModelIndex &sourceIndex) const
{
    if (!sourceIndex.isValid())
        return QModelIndex();

    return createIndex(sourceIndex.row(), 0);
}
