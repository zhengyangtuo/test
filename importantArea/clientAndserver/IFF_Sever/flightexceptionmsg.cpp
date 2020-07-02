#include "flightexceptionmsg.h"

FlightExceptionMsg::FlightExceptionMsg()
{
    //test
    triggerCriticalAreasNum = 2;
    triggerCriticalAreasID.append(5);
    triggerCriticalAreasID.append(10);
}

//反序列化
QDataStream& operator>>(QDataStream & inStream,FlightExceptionMsg& msg)
{

    return inStream;
}

//序列化
QDataStream& operator<<(QDataStream & outStream,const FlightExceptionMsg& msg)
{
    //目标地址
    outStream<<msg.flightException.getTargetAddr();
    //首次截获时间
    outStream<<msg.flightException.getFirstInterceptionTime();
    //通过的目标区域
    outStream<<msg.triggerCriticalAreasNum;
    for(const auto &i : msg.triggerCriticalAreasID)
    {
        outStream<<i;
    }
    return outStream;
}

void FlightExceptionMsg::msgSerialization(QDataStream &outStream)
{
    outStream<<123456;
    //首次截获时间
    outStream<<QDateTime::currentDateTime();
    //通过的目标区域
    outStream<<triggerCriticalAreasNum;
    for(const auto &i : triggerCriticalAreasID)
    {
        outStream<<i;
    }
}
