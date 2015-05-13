#ifndef ADDADMIDIALOG_H
#define ADDADMIDIALOG_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtGui>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class addAdmiDialog;
}

class addAdmiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addAdmiDialog(QWidget *parent = 0);
    void set_db(QSqlDatabase * db);
    ~addAdmiDialog();

private slots:
    void on_confirmAddAdmi_clicked();

    void on_cancelAddAdmi_clicked();

private:
    Ui::addAdmiDialog *ui;
    QSqlDatabase * pDB;
};

#endif // ADDADMIDIALOG_H
