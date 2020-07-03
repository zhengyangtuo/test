#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qrabbitmq.h"
#include<QPushButton>
#include"importarea.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加server作为路由键
    QStringList str=QStringList()<<"client";

    mqRabbitMQ=new QRabbitMQ(this);
    //队列绑定交换机与路由键
    mqRabbitMQ->SetRabbitClientParam(str);
    //添加信号与槽
    AddConnect();

}

void MainWindow::AddConnect(){

    connect(mqRabbitMQ,&QRabbitMQ::MsgSigal,this,&MainWindow::ReceiveMsg);
    connect(mqRabbitMQ,&QRabbitMQ::readyConnect,this,&MainWindow::ReadyConnectMsg);

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_connectBtn_clicked()
{
    bool ok;
    QString ip=ui->inputIp->text();
    quint16 port=ui->inputPort->text().toUInt();
    mqRabbitMQ->SetServerParam(ip,port);
    mqRabbitMQ->Start();

}

void MainWindow::on_sendBtn_clicked()
{
    importArea area;
    msgOut.clear();
    //定义输出流
    QDataStream outStream(&msgOut,QIODevice::WriteOnly);
    //设定输出流版本
    outStream.setVersion(QDataStream::Qt_5_11);
    //将重点区域的信息序列化到输入流中
    outStream<<area;
    //发送序列化信息到服务器
     mqRabbitMQ->SendMsg("server",msgOut);

    //显示自己发送的数据
    //    ui->textEdit->append("client:"+ui->inputMsg->text());
}

void MainWindow::ReceiveMsg(const QByteArray &Msg){
//    接受server发送的flightexception类信息
    msgIn=Msg;
    //定义输入流
    QDataStream inStream(&msgIn,QIODevice::ReadOnly);
    //设定输入流版本号
    inStream.setVersion(QDataStream::Qt_5_11);
    quint32 targetAddr;
    inStream>>targetAddr;
    QDateTime firstInterceptionTime;
    inStream>>firstInterceptionTime;
    ui->textEdit->append(QString::number(targetAddr));
    ui->textEdit->append(firstInterceptionTime.toString());
    quint16 a;
    quint16 b;
    quint16 c;
    inStream>>a>>b>>c;
    ui->textEdit->append(QString::number(a));
    ui->textEdit->append(QString::number(b));
    ui->textEdit->append(QString::number(c));


//    /*importantArea的信息*/
//    //测试自己接受到的消息
//    //qDebug()<<Msg;
//    //qDebug()<<QString(Msg).toUtf8();//测试将QString转换为utf8只要有零字节就会成为空
//    //清空之前发送的字节流
//    msgIn.clear();

//    importArea area;

//    msgIn=Msg;
//    //定义输入流
//    QDataStream inStream(&msgIn,QIODevice::ReadOnly);
//    //设定输入流版本号
//    inStream.setVersion(QDataStream::Qt_5_11);
//    //反序列化
//    inStream>>area;
////    提取出序列化信息的类型
//    quint16 type;
//    inStream>>type;
//    ui->textEdit->append("messageType:"+QString::number(type));
//    qDebug()<<type;
//    //根据类型交给不同的处理函数
//    switch (type) {
//    case messageType::importantAreaError:
//        DealImportAreaError(inStream);
//        break;
//    case messageType::createImportantArea:
//        DealNewImportantAreaMsg(inStream);
//        break;
//    case messageType::updateImportantArea:
//        DealUpdateImportantAreaMsg(inStream);
//        break;
//    case messageType::deleteImportantArea:
//        DealDeleteImportantAreaMsg(inStream);
//        break;
//    default:
//        break;
//    }
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
    //TODO(郑鑫尧):处理新建重点区域信息的函数
}

void MainWindow::DealUpdateImportantAreaMsg(QDataStream &inStream)
{
    //TODO(郑鑫尧):处理更新重点区域信息的函数
}

void MainWindow::DealDeleteImportantAreaMsg(QDataStream &inStream)
{
    //TODO(郑鑫尧):处理删除重点区域信息的函数
}



