#ifndef FLIGHTEXCEPTIONMSG_H
#define FLIGHTEXCEPTIONMSG_H

#include<QVector>
#include<QDataStream>
//#include<QDebug>
#include"flightexception.h"

class FlightExceptionMsg
{
public:
    FlightExceptionMsg();
    void msgSerialization(QDataStream &outStream);
    friend QDataStream& operator>>(QDataStream & inStream,FlightExceptionMsg& msg);
    friend QDataStream& operator<<(QDataStream & outStream,const FlightExceptionMsg& msg);
private:
    //飞行器异常信息
    FlightException flightException;
    //触发的重点区域数目
    quint16 triggerCriticalAreasNum;
    QVector<quint16> triggerCriticalAreasID;
};

#endif // FLIGHTEXCEPTIONMSG_H
