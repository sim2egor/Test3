#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mashinelist.h"
#include "mashinesmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType <MashinesModel> ("Mashines",1,0,"MashinesModel");

    MashineList mashineList;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("mashineList"), &mashineList);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
