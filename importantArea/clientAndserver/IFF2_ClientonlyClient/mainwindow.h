#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"qrabbitmq.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_connectBtn_clicked();

    void on_sendBtn_clicked();

    void receiveMsg(const QByteArray &Msg);

    void readyConnectMsg();
private:
    Ui::MainWindow *ui;

    QByteArray msgIn;

    QByteArray msgOut;

    QRabbitMQ *mqRabbitMQ;
};

#endif // MAINWINDOW_H
