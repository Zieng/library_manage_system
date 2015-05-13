#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    connect(ui->cancelLogin,SIGNAL(clicked()),this,SLOT(close()));
    ui->passwordEntry->setEchoMode(QLineEdit::Password);
    if(ui->accoutType->currentText()=="root")
        ui->nameLabel->setText("User Name:");
    else
        ui->nameLabel->setText("Admi Id:");
}

void LoginDialog::set_db(QSqlDatabase * db)
{
    pDB=db;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/*
 * this is one way to set the signal
void LoginDialog::on_cancelLogin_clicked()
{
    close();  //this will close the dialog
}*/

void LoginDialog::on_showPassword_toggled(bool checked)
{
    if(checked==false)
        ui->passwordEntry->setEchoMode(QLineEdit::Password);
    else
        ui->passwordEntry->setEchoMode(QLineEdit::Normal);
}

void LoginDialog::on_confirmLogin_clicked()
{
    if(ui->accoutType->currentText()=="root")
    {
        if(ui->nameEntry->text()=="library_admi" && ui->passwordEntry->text()=="jald234")
        {
            done(1);// 1 is for root
        }
        else
        {
            QMessageBox::information(this,"login Failed!","You are not root!");
        }
    }
    else  //administrator
    {
       // QMessageBox::information(this,"login sucessful","YOu choose the administrator");
        std::string  command;
        QString temp;
        temp="select admId from myLibrary.administrator where admId=\'"+ui->nameEntry->text()
                +"\' and admPassword=\'"+ui->passwordEntry->text()+"\'";
        command=temp.toUtf8().constData();
        QSqlQuery query(command.c_str());
        int rowNums=query.size();
        if(rowNums==0)
        {
            QMessageBox::information(this,"login Failed!","You are not valid administrator");
        }
        else if(rowNums<0)
        {
            QMessageBox::warning(this,"error!","someting wrong with the database!");
        }
        else
        {
            done(2);  // 2 is for administrator;
        }
    }
}

