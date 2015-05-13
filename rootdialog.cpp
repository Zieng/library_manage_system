#include "rootdialog.h"
#include "ui_rootdialog.h"

rootDialog::rootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rootDialog)
{
    ui->setupUi(this);
}

rootDialog::~rootDialog()
{
    delete ui;
}

void rootDialog::on_returnStart_clicked()
{
    done(1);
}

void rootDialog::set_db(QSqlDatabase * db)
{
    pDB=db;
}

void rootDialog::on_addAdmi_clicked()
{
    hide();
    addAdmiDialog * add=new addAdmiDialog;
    add->set_db(pDB);
    add->exec();
    show();
}



void rootDialog::on_deleteAdmi_clicked()
{
    hide();
    deleteAdmiDialog * delAdm=new deleteAdmiDialog;
    delAdm->exec();
    show();
}

void rootDialog::on_showAdmi_clicked()
{
     QSqlQuery query("SELECT * FROM myLibrary.administrator");
     QTableWidget* table = new QTableWidget();
     QStringList  header;

     header<<"ID"<<"Password"<<"Name"<<"Email";
     table->setHorizontalHeaderLabels(header);
     table->setColumnCount(query.record().count());
     table->setRowCount(query.size());

     int index=0;
     while (query.next())
     {
     table->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
     table->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
     table->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
     table->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
     index++;
     }

     table->show();
}
