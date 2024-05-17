#ifndef LOGBOOKCONTROLLER_H
#define LOGBOOKCONTROLLER_H

#include <QObject>

class LogBookController: public QObject
{
    Q_OBJECT
public:
    LogBookController();

    void setData();
};

#endif // LOGBOOKCONTROLLER_H
