#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qrabbitmq.h"
#include<QPushButton>
#include "flightexceptionmsg.h"
#include"importarea.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加server作为路由键
    QStringList str=QStringList()<<"server";

    mqRabbitMQ=new QRabbitMQ(this);
    //队列绑定交换机与路由键
    mqRabbitMQ->SetRabbitClientParam(str);
    //添加信号与槽
    AddConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddConnect(){

    connect(mqRabbitMQ,&QRabbitMQ::MsgSigal,this,&MainWindow::ReceiveMsg);
    connect(mqRabbitMQ,&QRabbitMQ::readyConnect,this,&MainWindow::ReadyConnectMsg);

}

void MainWindow::on_connectBtn_clicked()
{

    QString ip=ui->InputIp->text();
    quint16 port=static_cast<quint16>(ui->InputPort->text().toUInt());

    //设置RabbitMQ类的ip与端口,并进行连接
    mqRabbitMQ->SetServerParam(ip,port);

    mqRabbitMQ->Start();



}

void MainWindow::on_sendBtn_clicked()
{
    FlightExceptionMsg flightExceptionMsg;
    msgOut.clear();

    //定义输出流
    QDataStream outStream(&msgOut,QIODevice::WriteOnly);
    //设定输出流版本号
    outStream.setVersion(QDataStream::Qt_5_11);
    //序列化
    outStream<<flightExceptionMsg;
    //发送数据到路由键为client的队列
    mqRabbitMQ->SendMsg("client",msgOut);
    //显示自己发送的信息
//    QByteArray str;
//    str.append(ui->lnputMsg->text());
//    mqRabbitMQ->SendMsg("client",str);
//    ui->textEdit->append("server:"+ui->lnputMsg->text());
}

void MainWindow::ReceiveMsg(const QByteArray &Msg){
    //测试自己接受到的消息
    //qDebug()<<Msg;
    //qDebug()<<QString(Msg).toUtf8();//测试将QString转换为utf8只要有零字节就会成为空
    //清空之前发送的字节流
    msgIn.clear();

    importArea area;

    msgIn=Msg;
    //定义输入流
    QDataStream inStream(&msgIn,QIODevice::ReadOnly);
    //设定输入流版本号
    inStream.setVersion(QDataStream::Qt_5_11);
    //反序列化
    inStream>>area;
    //将反序列化后的信息显示在空白行
//    ui->textEdit->append("importantAreaType:"+QString::number(area.getMessageType()));
//    ui->textEdit->append("importantAreaNum:"+QString::number(area.getImportantAreaNum()));
//    for(const auto&i:area.getImportantAreaId()){
//        ui->textEdit->append("importAreaID:"+QString::number(i));
//    }
//    提取出序列化信息的类型
    quint16 type;
    inStream>>type;
    ui->textEdit->append("messageType:"+QString::number(type));
    qDebug()<<type;
    //根据类型交给不同的处理函数
    switch (type) {
    case messageType::importantAreaError:
        DealImportAreaError(inStream);
        break;
    case messageType::createImportantArea:
        //TODO(郑鑫尧):处理创建重点区域的函数
        break;
    case messageType::updateImportantArea:
        //TODO()
        break;
    case messageType::deleteImportantArea:

        break;
    default:
        break;
    }

}


void MainWindow::ReadyConnectMsg(){

    ui->textEdit->append("ready connect");
}

void MainWindow::DealImportAreaError(QDataStream &inStream){

    quint16 num;
    inStream>>num;
    ui->textEdit->append("importantAreaNum:"+QString::number(num));
    qDebug()<<num;
    QVector<quint16> id;
    inStream>>id;
    for(const auto&i:id){
        qDebug()<<i;
        ui->textEdit->append("importAreaID:"+QString::number(i));
    }
}

void MainWindow::DealNewImportantAreaMsg(QDataStream &inStream)
{

}

void MainWindow::DealUpdateImportantAreaMsg(QDataStream &inStream)
{

}

void MainWindow::DealDeleteImportantAreaMsg(QDataStream &inStream)
{

}

