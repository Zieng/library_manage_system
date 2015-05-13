#ifndef ADMTABWINDOW_H
#define ADMTABWINDOW_H

#include <QTabWidget>

namespace Ui {
class AdmTabWindow;
}

class AdmTabWindow : public QTabWidget
{
    Q_OBJECT

public:
    explicit AdmTabWindow(QWidget *parent = 0);
    ~AdmTabWindow();

private:
    Ui::AdmTabWindow *ui;
};

#endif // ADMTABWINDOW_H
