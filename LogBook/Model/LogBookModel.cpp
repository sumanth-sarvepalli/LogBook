#include "LogBookModel.h"

LogBookModel::LogBookModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

LogBookModel* LogBookModel::getInstance()
{
    static LogBookModel logBookModelObj;
    return &logBookModelObj;
}

int LogBookModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_logData.size();
}

int LogBookModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return MaxRole;
}

QVariant LogBookModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    int rowIndex = index.row();
    QVariant roleValue = QVariant();

    if (Qt::DisplayRole == role)
        roleValue = m_logData[rowIndex];

    return roleValue;
}

QHash<int, QByteArray> LogBookModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}

void LogBookModel::addData(QString logEntry)
{
    m_logData.append(logEntry);
}
