/**********************************************************************
 * 数据连接处理类头文件
 * 创建者：2020-5-6 陈俊俊
 * 修改者：
 **********************************************************************/ 
#ifndef NETCONNECTOR_H
#define NETCONNECTOR_H

#include<QObject>
#include<QString>
#include<QHostAddress>
#include "qrabbitmq.h"

/* *
 * NetConnector是客户端通信数据处理的类，创建NetConnector连接消息队列，通过消息队列来进行通信
 * Example:
 * NetConnector *m_netConnector = new NetConnector(127.0.0.1,5672);//连接rabbitMq服务器
 * m_netConnector.SetRabbitClientParam(bindingKeyList);
 * m_netConnector->start()//启动消息队列连接
 * */
class NetConnector: public QObject
{
     Q_OBJECT
public:
    /* *
     * 函数功能:默认构造NetConnector
     * 调用表:无
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
     * */
     explicit NetConnector(QObject *parent = nullptr);

    /******************************************************************
     * 函数功能:构造NetConnector，并设定好连接消息队列服务器的ip地址和端口号
     * 调用表:NetConnector::SetServerParam
     * 输入参数:ipAdress IP地址
     *         Port 端口号
     * 输出参数:无
     * 返回值:无
     * ***************************************************************/
    explicit NetConnector(const QString &ipAddress,const quint16 port,QObject *parent = nullptr);

    /******************************************************************
     * 函数功能:设置RabbitMQ服务器的ip和端口号
     * 调用表:QRabbitMQ::SetServerParam
     * 被调用表:无
     * 输入参数:ip IP地址;port 端口号
     * 输出参数:无
     * 返回值:无
     * ***************************************************************/
    inline void SetServerParam(const QString &ipAddress, const quint16 port);

    /******************************************************************
     * 函数功能:设置当前消息队列的绑定RoutingKey列表
     * 调用表:QRabbitMQ::SetRabbitClientParam
     * 被调用表:无
     * 输入参数:bindingKeyList RoutingKey的列表
     * 输出参数:无
     * 返回值:无
     * ***************************************************************/
    inline void SetRabbitClientParam(const QStringList &bindingKeyList);
public slots:
    /******************************************************************
     * 函数功能:启动与消息队列的连接。槽函数
     * 调用表:QRabbitMQ::Start
     * 被调用表:无
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
     * ***************************************************************/
    void Start();

   /******************************************************************
    * 函数功能:接收消息队列的数据。槽函数
    * 调用表:无
    * 被调用表:无
    * 输入参数:msg 从消息队列接收的字节流数据
    * 输出参数:无
    * 返回值:无
    * ***************************************************************/
    void RecivedMsg(const QByteArray &msg);

   /******************************************************************
    * 函数功能:发送数据至消息队列交换机。槽函数
    * 调用表:
    * 被调用表:无
    * 输入参数:routingKey 发送的消息的RoutingKey;msg 需要发送的字节流消息
    * 输出参数:无
    * 返回值:无
    * ***************************************************************/
    void SendMsg(const QString &routingKey, const QByteArray &msg);

   /******************************************************************
    * 函数功能:接收消息队列客户端的错误并处理
    * 调用表:
    * 被调用表:无
    * 输入参数:无
    * 输出参数:无
    * 返回值:无
    * ***************************************************************/
    void ErrorDealing(QAMQP::Error error);
private:
    
   //消息队列客户端的封装
   QRabbitMQ *mQrabbitMQ;
};

#endif // NETCONNECTOR_H
