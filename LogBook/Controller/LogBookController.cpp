#include "LogBookController.h"
#include "Model/LogBookModel.h"

LogBookController::LogBookController()
{

}

void LogBookController::setData()
{
    QString data1 = "01 2024-03-29T08:30:00.000Z abcd7564 - This is a log message 1";
    QString data2 = "02 2024-03-30T11:40:00.000Z abcd7564 - This is a log message 2";
    QString data3 = "03 2024-03-31T09:30:57.000Z abcd7564 - This is a log message 3";
    QString data4 = "04 2024-04-01T11:30:57.000Z abcd7564 - This is a log message 4";

    for(int i = 0; i < 50; i++){
        LogBookModel::getInstance()->addData(data1);
        LogBookModel::getInstance()->addData(data2);
        LogBookModel::getInstance()->addData(data3);
        LogBookModel::getInstance()->addData(data4);
    }
}
