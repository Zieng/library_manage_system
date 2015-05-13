#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::set_db(QSqlDatabase * db)
{
    pDB=db;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startLogin_clicked()
{
    LoginDialog *login=new LoginDialog(this);
    login->set_db(pDB);
    int loginState=login->exec();

    if(loginState==1)//root
    {
        QMessageBox::information(this,"login sucessful","Welcome Back! root!");
        root();
    }
    else if(loginState==2) //administrator
    {
        QMessageBox::information(this,"login sucessful","Welcome Back! administrator!");
        admi();
    }
}

void MainWindow::root()
{
    hide();
    rootDialog *rootwindow=new rootDialog;
    rootwindow->set_db(pDB);
    rootwindow->exec();
    show();
}

void MainWindow::admi()
{
    hide();
    admiDialog * admiwindow=new admiDialog;
    admiwindow->exec();
    show();
}

void MainWindow::visitor()
{

}
