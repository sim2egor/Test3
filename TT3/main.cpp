#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSql>

#include "mashinelist.h"
#include "mashinesmodel.h"
#include "initdb.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    // DB init
    //DataBase database;
    if (!QSqlDatabase::drivers().contains("QSQLITE")){
        qDebug() <<"error open DB";
    return -1;}
    // Initialize the database:
    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        qDebug() <<"error open DB";
        return -1;
    }

    qmlRegisterType <MashinesModel> ("Mashines",1,0,"MashinesModel");
    qmlRegisterUncreatableType <MashineList> ("Mashines",1,0,"MashineList",
                                              QStringLiteral("MashineList not created!!!"));

    MashineList mashList;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("mashList"), &mashList);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
