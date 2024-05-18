#ifndef LOGBOOKSORTPROXYMODEL_H
#define LOGBOOKSORTPROXYMODEL_H

#include <QSortFilterProxyModel>

class LogBookSortProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    static LogBookSortProxyModel* getInstance();

protected:
    // QSortFilterProxyModel interface
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;

private:
    explicit LogBookSortProxyModel(QObject *parent = nullptr);
};

#endif // LOGBOOKSORTPROXYMODEL_H
