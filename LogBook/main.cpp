#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Model/LogBookModel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("logBookModel", LogBookModel::getInstance());
    const QUrl url(u"qrc:/LogBook/View/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
