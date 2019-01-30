#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include "packet.h"
#include <QThread>
#include "masterthread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

//signals :
//     void set_cmd(const QString &s);

private slots:
    void on_open_button_clicked();
    void on_read_version_button_clicked();
    void on_update_firmware_button_clicked();

private:
    Ui::Dialog *ui;
    QString portName;
    bool mFirstOpen;
    MasterThread mThread;
};

#endif // DIALOG_H
