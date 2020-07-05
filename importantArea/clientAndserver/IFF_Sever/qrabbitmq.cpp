#include "qrabbitmq.h"
QRabbitMQ::QRabbitMQ(QObject *parent) :
    QObject(parent)
{
    m_exchangerName = "direct_exchanger";
}

void QRabbitMQ::Start()
{
    connect(&m_client, SIGNAL(connected()), this, SLOT(ClientConnected()));
    connect(&m_client, SIGNAL(error(QAMQP::Error error)), this, SLOT(ErrorDealing(QAMQP::Error error)));
//    connect(this,&QRabbitMQ::MsgSigal,this,&QRabbitMQ::ReceiveMsg);
    //连接服务器
    m_client.connectToHost(QHostAddress(m_serverIP), m_serverPort);
}

void QRabbitMQ::ClientConnected()
{
    //声明消息队列
    QAmqpExchange *exchange = m_client.createExchange(m_exchangerName);
    connect(exchange, SIGNAL(declared()), this, SLOT(ExchangeDeclared()));
    exchange->declare(QAmqpExchange::Direct);
    qDebug() << "RabbitMQ connect to server ok";
    emit readyConnect();
}

void QRabbitMQ::ExchangeDeclared()
{
    //获取绑定的消息队列 并将消息队列的接收消息信号与消息接收槽函数绑定
    QAmqpQueue *temporaryQueue = m_client.createQueue();
    connect(temporaryQueue, SIGNAL(declared()), this, SLOT(QueueDeclared()));
    connect(temporaryQueue, SIGNAL(messageReceived()), this, SLOT(MessageReceived()));
    temporaryQueue->declare(QAmqpQueue::Exclusive);
}

void QRabbitMQ::QueueDeclared()
{
    //获取到创建成功的消息队列
    QAmqpQueue *temporaryQueue = qobject_cast<QAmqpQueue*>(sender());
    if (!temporaryQueue){
        return;
    }

    // 设置消费消息队列的option为不用ack模式
    temporaryQueue->consume(QAmqpQueue::coNoAck);

    //绑定消息队列的RoutingKey
    foreach (QString severity, m_bindingKeyList)
        temporaryQueue->bind(m_exchangerName, severity);

}

void QRabbitMQ::MessageReceived()
{
    //从客户端的消息队列中获取到接受到的消息
    QAmqpQueue *temporaryQueue = qobject_cast<QAmqpQueue*>(sender());
    if (!temporaryQueue){
        qDebug()<<"empty";
        return;
        }

    QAmqpMessage message = temporaryQueue->dequeue();

    QByteArray msg = message.payload();
    emit MsgSigal(msg);
}

void QRabbitMQ::ErrorDealing(QAMQP::Error error){
    emit Error(error);
}

void QRabbitMQ::SendMsg(const QString &routingKey,const QByteArray &msg)
{
    //向交换机发送消息
    QAmqpExchange *exchange = m_client.createExchange(m_exchangerName);

    exchange->publish(msg, routingKey,QLatin1String("text.plain"));
}

void QRabbitMQ::SetServerParam(const QString &ip, const quint16 port)
{
    m_serverIP = ip;
    m_serverPort = port;
}

void QRabbitMQ::SetRabbitClientParam(const QStringList &bindingKeyList)
{
    m_bindingKeyList = bindingKeyList;
}

