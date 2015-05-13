#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtGui>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>


namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    void set_db(QSqlDatabase * db);
    ~LoginDialog();

private slots:


    void on_showPassword_toggled(bool checked);

    void on_confirmLogin_clicked();

private:
    Ui::LoginDialog *ui;
    QSqlDatabase * pDB;
};

#endif // LOGINDIALOG_H
