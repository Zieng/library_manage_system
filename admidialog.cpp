#include "admidialog.h"
#include "ui_admidialog.h"

admiDialog::admiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admiDialog)
{
    ui->setupUi(this);
}

admiDialog::~admiDialog()
{
    delete ui;
}
