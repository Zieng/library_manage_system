#include "addadmidialog.h"
#include "ui_addadmidialog.h"

addAdmiDialog::addAdmiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAdmiDialog)
{
    ui->setupUi(this);
}

addAdmiDialog::~addAdmiDialog()
{
    delete ui;
}

void addAdmiDialog::on_confirmAddAdmi_clicked()
{
    std::string  command;
    QString temp;
    QString checkExist;
    checkExist="select admId from myLibrary.administrator where admId=\'"+ui->admIDEntry->text()
            +"\' and admPassword=\'"+ui->admPasswordEntry->text()+"\'";
    command=checkExist.toUtf8().constData();
    QSqlQuery query;
    query.exec(command.c_str());
    int rowNums=0;
    rowNums=query.size();
    if(rowNums>0)
    {
        QMessageBox::information(this,"add Failed!","administrator already exists!");
    }
    else if(rowNums<0)
    {
        QMessageBox::warning(this,"error!","someting wrong with the database!");
    }
    else
    {
        temp="insert into myLibrary.administrator(admId,admPassword,name,email) values(\'"+ui->admIDEntry->text()
                +"\',\'"+ui->admPasswordEntry->text()+"\',\'"+ui->admNameEntry->text()+"\',\'"+ui->emailEntry->text()+"\')";
        command=temp.toUtf8().constData();
        query.exec(command.c_str());

         /*add to check if its successful*/
    }

}

void addAdmiDialog::on_cancelAddAdmi_clicked()
{
    done(1);
}

void addAdmiDialog::set_db(QSqlDatabase *db)
{
    pDB=db;
}
