#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include <Controller/LogBookController.h>
#include <Model/LogBookModel.h>
#include <Model/LogBookProxyModel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();

    qreal screenWidth = screenGeometry.width();
    qreal screenHeight = screenGeometry.height();
    LogBookController logBookController;
    logBookController.setData();

    engine.rootContext()->setContextProperty("screenWidth", screenWidth);
    engine.rootContext()->setContextProperty("screenHeight", screenHeight);
    engine.rootContext()->setContextProperty("logBookProxyModel", LogBookProxyModel::getInstance());

    const QUrl url(u"qrc:/LogBook/View/Main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
