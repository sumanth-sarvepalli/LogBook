#ifndef LOGBOOKMODEL_H
#define LOGBOOKMODEL_H

#include <QAbstractTableModel>

class LogBookModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    static LogBookModel *getInstance();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // QAbstractTableModel interface
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addData(QString logEntry);

private:
    explicit LogBookModel(QObject *parent = nullptr);

    QList<QString> m_logData;
};

#endif // LOGBOOKMODEL_H
