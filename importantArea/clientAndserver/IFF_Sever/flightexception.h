#ifndef FLIGHTEXCEPTION_H
#define FLIGHTEXCEPTION_H

#include<QObject>
#include<QDateTime>

class FlightException
{
public:
    FlightException();
    friend QDataStream& operator>>(QDataStream & inStream,FlightException& msg);
    friend QDataStream& operator<<(QDataStream & outStream,const FlightException& msg);

    quint32 getTargetAddr() const;
    void setTargetAddr(const quint32 &value);

    QDateTime getFirstInterceptionTime() const;
    void setFirstInterceptionTime(const QDateTime &value);

private:
    //目标地址
    quint32 targetAddr;
    //异常时间
    QDateTime exceptionTime;
    //首次截获时间
    QDateTime firstInterceptionTime;
    //异常类型
//    ExceptionModeEnum exceptionMode;
    //是否确认
    bool isAcknowledge;
    //确认时间
    QDateTime ackTime;
    //异常描述
    QString exceptionDesperation;
    //异常备注信息
    QString exceptionRemarks;
    //是否被存入数据库
    bool isStored;
    //是否被修改
    bool isModify;
};

#endif // FLIGHTEXCEPTION_H
