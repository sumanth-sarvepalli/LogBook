#ifndef LOGBOOKMODEL_H
#define LOGBOOKMODEL_H

#include <QAbstractTableModel>
#include <QMap>

typedef struct LogData
{
    int m_id;
    QString m_date;
    QString m_time;
    QString m_message;
}LogData;

class LogBookModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Roles{
        IdRole,
        DateRole,
        TimeRole,
        MessageRole,
        MaxRole
    };

    static LogBookModel *getInstance();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // QAbstractTableModel interface
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void updateData();

private:
    explicit LogBookModel(QObject *parent = nullptr);
    QMap<int, LogData> m_logData;
};

#endif // LOGBOOKMODEL_H
