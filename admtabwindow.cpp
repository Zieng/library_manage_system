#include "admtabwindow.h"
#include "ui_admtabwindow.h"

AdmTabWindow::AdmTabWindow(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::AdmTabWindow)
{
    ui->setupUi(this);
}

AdmTabWindow::~AdmTabWindow()
{
    delete ui;
}
