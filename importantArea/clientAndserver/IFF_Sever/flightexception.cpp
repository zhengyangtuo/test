#include "flightexception.h"

FlightException::FlightException()
{
}

quint32 FlightException::getTargetAddr() const
{
    return 1234567890;
}

void FlightException::setTargetAddr(const quint32 &value)
{
    targetAddr = value;
}

QDateTime FlightException::getFirstInterceptionTime() const
{
    return QDateTime::currentDateTime();
}

void FlightException::setFirstInterceptionTime(const QDateTime &value)
{
    firstInterceptionTime = value;
}

QDataStream& operator>>(QDataStream & inStream,FlightException& msg)
{
    //
    return inStream;
}

QDataStream& operator<<(QDataStream & outStream,const FlightException& msg)
{
    //
    return outStream;
}

