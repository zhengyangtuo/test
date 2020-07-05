#include "netconnector.h"

NetConnector::NetConnector(QObject *parent) :
    QObject(parent)
{
    mQrabbitMQ = new QRabbitMQ();
}

NetConnector::NetConnector(const QString &ipAddress,const quint16 port,QObject *parent) :
    QObject(parent)
{
    mQrabbitMQ = new QRabbitMQ();
    SetServerParam(ipAddress,port);
}

void NetConnector::SetServerParam(const QString &ipAddress, const quint16 port)
{
    mQrabbitMQ->SetServerParam(ipAddress,port);
    qDebug()<<"Server is ok!";
}

void NetConnector::SetRabbitClientParam(const QStringList &bindingKeyList)
{
    mQrabbitMQ->SetRabbitClientParam(bindingKeyList);
}

void NetConnector::Start()
{
   mQrabbitMQ->Start();
}

void NetConnector::RecivedMsg(const QByteArray &msg)
{
    //TODO(Chenjunjun):消息解包之后的处理
}

void NetConnector::ErrorDealing(QAMQP::Error error)
{
    //TODO(Chenjunjun):错误消息的处理
}
void NetConnector::SendMsg(const QString &routingKey,const QByteArray &msg)
{
//    mQrabbitMQ->SendMsg(routingKey,msg);
}
