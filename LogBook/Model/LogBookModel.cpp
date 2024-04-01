#include "LogBookModel.h"

LogBookModel::LogBookModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    updateData();
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

    int rowCount = index.row();
    int columnCount = index.column();

    QVariant roleValue = QVariant();

    switch (columnCount) {
    case IdRole:
        roleValue = m_logData[rowCount].m_id;
        break;
    case DateRole:
        roleValue = m_logData[rowCount].m_date;
        break;
    case TimeRole:
        roleValue = m_logData[rowCount].m_time;
        break;
    case MessageRole:
        roleValue = m_logData[rowCount].m_message;
        break;
    default:
        break;
    }

    return roleValue;
}

QHash<int, QByteArray> LogBookModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DateRole] = "sDate";
    roles[TimeRole] = "sTime";
    roles[MessageRole] = "sMessage";
    return roles;
}

void LogBookModel::updateData()
{
    // sample Data
    m_logData.insert(0, LogData{1, "31-03-2024", "8:30:00 AM", "This is a log message"});
    m_logData.insert(1, LogData{2, "31-03-2024", "8:30:00 AM", "This is a log message"});
    m_logData.insert(2, LogData{3, "31-03-2024", "8:30:00 AM", "This is a log message"});
    m_logData.insert(3, LogData{4, "31-03-2024", "8:30:00 AM", "This is a log message"});

    // fixed data
    LogData l_logDataObj;
    l_logDataObj.m_date = "01-04-2024";
    l_logDataObj.m_time = "5:30:00 PM";
    l_logDataObj.m_message = "This is a sample log message";

    for (int i = 4; i < 10; ++i) {
        l_logDataObj.m_id = i+1;
        m_logData.insert(i, l_logDataObj);
    }

    // Insert rows
    beginInsertRows(QModelIndex(), 0, 0);

    beginResetModel();
    endResetModel();
}



