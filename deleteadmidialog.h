#ifndef DELETEADMIDIALOG_H
#define DELETEADMIDIALOG_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtGui>
#include <QTableWidget>
#include <QStringList>
#include <QDebug>
#include <iostream>
#include <string>
#include <QMessageBox>

namespace Ui {
class deleteAdmiDialog;
}

class deleteAdmiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit deleteAdmiDialog(QWidget *parent = 0);
    ~deleteAdmiDialog();

private slots:
    void on_deleteAdmi_clicked();

    void on_cancelDeleteAdmi_clicked();

private:
    Ui::deleteAdmiDialog *ui;
};

#endif // DELETEADMIDIALOG_H
