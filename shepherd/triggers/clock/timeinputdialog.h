#ifndef TIMEINPUTDIALOG_H
#define TIMEINPUTDIALOG_H

#include <QtGui/QDialog>

#ifdef Q_WS_MAEMO5
#include <QMaemo5TimePickSelector>
#endif

namespace Ui {
    class TimeInputDialog;
}

class TimeInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeInputDialog(QWidget *parent = 0);
    QTime time();
    ~TimeInputDialog();

private:
    Ui::TimeInputDialog *ui;
#ifdef Q_WS_MAEMO5
    QMaemo5TimePickSelector m5pick;
#endif
};

#endif // TIMEINPUTDIALOG_H
