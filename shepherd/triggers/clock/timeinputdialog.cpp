#include "timeinputdialog.h"
#include "ui_timeinputdialog.h"

TimeInputDialog::TimeInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeInputDialog)
{
    ui->setupUi(this);
#ifdef Q_WS_MAEMO5
    ui->horizontalLayout_2->insertWidget(0, m5pick);
#endif

}

QTime TimeInputDialog::time()
{
#ifdef Q_WS_MAEMO5
    return m5pick.currentTime();
#else
    return ui->timeEdit->time();
#endif
}

TimeInputDialog::~TimeInputDialog()
{
    delete ui;
}
