#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtGui>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>
#include "rootdialog.h"
#include "logindialog.h"
#include "admidialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void set_db(QSqlDatabase * db);
    void root();
    void admi();
    void visitor();

    ~MainWindow();

private slots:
    void on_startLogin_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase * pDB;

};

#endif // MAINWINDOW_H
