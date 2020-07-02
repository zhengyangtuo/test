#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"qrabbitmq.h"
#include"importarea.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*
     * 函数功能:构造初始化界面，并为mqRabbitMQ分配空间，设置路由键，绑定信号与槽
     * 调用表: 调用QRabbitMQ类中的SetRabbitClientParam()
     * 被调用表:无
     * 输入参数:父指针对象
     * 输出参数:无
     * 返回值:无
    */
    explicit MainWindow(QWidget *parent = nullptr);
    /*
     * 函数功能:析构函数，释放界面的空间
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    ~MainWindow();
    /*
     * 函数功能:反序列化异常信息中的重点区域数目以及id
     * 调用表:无
     * 被调用表:ReceiveMsg()函数中有调用
     * 输入参数:输入除去报文类型后的序列化重点区域的异常信息
     * 输出参数:无
     * 返回值:无
    */
    void DealImportAreaError(QDataStream &inStream);
    /*
     * 函数功能:绑定信号与槽
     * 调用表:无
     * 被调用表:被本类的构造函数调用
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void AddConnect();
private slots:
    /*
     * 函数功能:点击connect按钮后的触发的连接RabbitMQ服务的槽函数
     * 绑定表:ui中的connectBtn的clicked信号，connect函数是ui界面转到槽
     * 调用表:ui中connectBtn转到槽,mqRabbitMQ类中SetServerParam()与Start()
     * 被调用表:无
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void on_connectBtn_clicked();
    /*
     * 函数功能:点击send按钮后的触发的发送序列化数据给队列
     * 绑定表:ui中的sendBtn的clicked信号，connect函数是自动生成的转到槽
     * 调用表:ui中的sendBtn转到槽
     * 被调用表:无
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void on_sendBtn_clicked();
    /*
     * 函数功能:接受序列化数据，并解析报文类型，将其交于对应的处理函数
     * 绑定表:此槽函数与QRabbitMQ::MsgSigal 绑定，connect函数位于AddConnect()内
     * 调用表:当解析的报文类型为，调用函数为DealImportAreaError(QDataStream &inStream)
     * 被调用表:QRabbitMQ中的MessageReceived()函数中的MsgSigal信号
     * 输入参数:接受的序列化数据
     * 输出参数:无
     * 返回值:无
    */
    void ReceiveMsg(const QByteArray &Msg);
    /*
     * 函数功能:成功连接RabbitMQ服务器显示"ready connect"
     * 绑定表:此槽函数与QRabbitMQ::readyConnect绑定,connect函数位于AddConnect()内
     * 调用表:无
     * 被调用表:析构函数
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void ReadyConnectMsg();

private:
    Ui::MainWindow *ui;

    QByteArray msgOut;//输出的序列化数据

    QByteArray msgIn;//输入的序列化数据

    QRabbitMQ *mqRabbitMQ;//RabbitMq的类对象
};

#endif // MAINWINDOW_H
