#ifndef LOGBOOKPROXYMODEL_H
#define LOGBOOKPROXYMODEL_H

#include <QQmlEngine>
#include <QAbstractProxyModel>

class LogBookProxyModel: public QAbstractProxyModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    enum Roles{
        IdRole,
        DateRole,
        TimeRole,
        MessageRole,
        MaxRole
    };

    static LogBookProxyModel *getInstance();

    // QAbstractItemModel interface
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    // QAbstractProxyModel interface
protected:
    QModelIndex mapToSource(const QModelIndex &proxyIndex) const;
    QModelIndex mapFromSource(const QModelIndex &sourceIndex) const;

private:
    explicit LogBookProxyModel(QObject *parent = nullptr);
};

#endif // LOGBOOKPROXYMODEL_H
