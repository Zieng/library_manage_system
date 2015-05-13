#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtGui>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("myLibrary");
    db.setUserName("library_admi");
    db.setPassword("jald234");
    if (!db.open())
    {
          QMessageBox::critical(0, QObject::tr("Database Error"),
                    db.lastError().text());
    }

    MainWindow w;
    w.set_db(&db);
    w.show();

    return a.exec();
}
