#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_open_button_clicked();

    void on_read_version_button_clicked();

private:
    Ui::Dialog *ui;
    QSerialPort *mSerialPort;
    QString portName;
    bool mIsOpen;
};

#endif // DIALOG_H