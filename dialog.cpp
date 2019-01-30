#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QDate>
//#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QString serialPortItemName = info.manufacturer();
        serialPortItemName = info.portName();
        ui->serial_box->addItem(serialPortItemName);
    }
//
//    connect(this, SIGNAL(set_cmd(QString), &MasterThread, SLOT(thread_get_cmd(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_open_button_clicked()
{
    QString currentPortName;
    bool currentPortNameChanged = false;

    currentPortName =  ui->serial_box->currentText();
    if (!mFirstOpen) {
        portName = currentPortName;
        mFirstOpen = true;
        currentPortNameChanged = true;
    } else {

        if (currentPortName != portName) {
            portName = currentPortName;
            qDebug() << "portname:" << portName;
            currentPortNameChanged = true;
        }
    }

     if (currentPortNameChanged) {
//         mThread.start();

//         mThread.thread_get_cmd(1, portName);
     }
}

void Dialog::on_read_version_button_clicked()
{

}

void Dialog::on_update_firmware_button_clicked()
{

}


//void Dialog::on_test_button_clicked()
//{

//}

//void Dialog::on_test_button_2_clicked()
//{

//}

//void Dialog::on_test_button_3_clicked()
//{

//}

//void Dialog::on_test_button_4_clicked()
//{

//}
