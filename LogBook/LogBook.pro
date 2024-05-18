QT += quick

SOURCES += \
        Controller/LogBookController.cpp \
        Model/LogBookModel.cpp \
        Model/LogBookProxyModel.cpp \
        Model/LogBookSortProxyModel.cpp \
        main.cpp

HEADERS += \
    Controller/LogBookController.h \
    Model/LogBookModel.h \
    Model/LogBookProxyModel.h \
    Model/LogBookSortProxyModel.h

resources.files = View/Main.qml View/UserLog.qml View/LogBook.qml Images/logbook.svg
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
