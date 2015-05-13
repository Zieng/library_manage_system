#ifndef ADMIDIALOG_H
#define ADMIDIALOG_H

#include <QDialog>

namespace Ui {
class admiDialog;
}

class admiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit admiDialog(QWidget *parent = 0);
    ~admiDialog();

private:
    Ui::admiDialog *ui;
};

#endif // ADMIDIALOG_H
