#ifndef ROOTDIALOG_H
#define ROOTDIALOG_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtGui>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>
#include "addadmidialog.h"
#include "deleteadmidialog.h"

namespace Ui {
class rootDialog;
}

class rootDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rootDialog(QWidget *parent = 0);
    void set_db(QSqlDatabase * db);
    ~rootDialog();

private slots:
    void on_returnStart_clicked();

    void on_addAdmi_clicked();

    void on_deleteAdmi_clicked();

    void on_showAdmi_clicked();

private:
    Ui::rootDialog *ui;
    QSqlDatabase * pDB;
};

#endif // ROOTDIALOG_H
