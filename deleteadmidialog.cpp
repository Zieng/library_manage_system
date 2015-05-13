#include "deleteadmidialog.h"
#include "ui_deleteadmidialog.h"

deleteAdmiDialog::deleteAdmiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteAdmiDialog)
{
    ui->setupUi(this);
}

deleteAdmiDialog::~deleteAdmiDialog()
{
    delete ui;
}

void deleteAdmiDialog::on_deleteAdmi_clicked()
{
    std::string  command;
    QString temp;
    QString checkExist;
    checkExist="select admId from myLibrary.administrator where admId=\'"+ui->admIdEntry->text()+"\'";

    command=checkExist.toUtf8().constData();
    QSqlQuery query;
    query.exec(command.c_str());
    int rowNums=0;
    rowNums=query.size();
    if(rowNums==0)
    {
        QMessageBox::information(this,"delete Failed!","administrator not exists!");
    }
    else if(rowNums<0)
    {
        QMessageBox::warning(this,"error!","someting wrong with the database!");
    }
    else
    {
        temp="delete from myLibrary.administratorwhere admId=\'"+ui->admIdEntry->text()+"\'";

        command=temp.toUtf8().constData();
        query.exec(command.c_str());

         /*add to check if its successful*/
    }
}

void deleteAdmiDialog::on_cancelDeleteAdmi_clicked()
{
    done(1);
}
