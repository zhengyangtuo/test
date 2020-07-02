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
    QStringList str=QStringList()<<"client";
    mqRabbitMQ=new QRabbitMQ(this);
    mqRabbitMQ->SetRabbitClientParam(str);

    connect(mqRabbitMQ,&QRabbitMQ::MsgSigal,this,&MainWindow::receiveMsg);
    connect(mqRabbitMQ,&QRabbitMQ::readyConnect,this,&MainWindow::readyConnectMsg);

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
    outStream<<area;
//    outStream<<area.getMessageType();
//    outStream<<area.getImportantAreaNum();
//    qDebug()<<area.getImportantAreaNum();
//    outStream<<area.getImportantAreaId();
//    for(const auto &i:area.getImportantAreaId()){
//    outStream<<i;
//    }
//输出自己发送的信息
//    QByteArray str;
//    str.append(ui->inputMsg->text());
     mqRabbitMQ->SendMsg("server",msgOut);
    //测试反序列化
    QByteArray msg=msgOut;

    QDataStream inStream(&msg,QIODevice::ReadOnly);
    inStream.setVersion(QDataStream::Qt_5_11);

    inStream>>area;
    qDebug()<<area.getMessageType();
    qDebug()<<area.getImportantAreaNum();
    for(const auto &i:area.getImportantAreaId()){
     qDebug()<<QString::number(i)+"asdas";
    }

    //显示自己发送的数据
    //    ui->textEdit->append("client:"+ui->inputMsg->text());
}

void MainWindow::receiveMsg(const QByteArray &Msg){
//    qDebug()<<QString(Msg).toUtf8()+"123";
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


//    QString str=QString(Msg);

//    ui->textEdit->append("server:"+str);
}


void MainWindow::readyConnectMsg(){

    ui->textEdit->append("ready connect");
}



