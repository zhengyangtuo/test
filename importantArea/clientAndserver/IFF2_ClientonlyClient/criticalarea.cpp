#include "criticalarea.h"

CriticalArea::CriticalArea()
{

}

void CriticalArea::SetGeometry(QString Geometry)
{


}

bool CriticalArea::IsActive()
{
    return true;
}

bool CriticalArea::Contains(QPoint pos)
{
    return true;
}
bool CriticalArea::CheckAltitude(quint32 value)
{
    return true;
}
bool CriticalArea::CheckSpeedVertical(quint32 value)
{
    return true;
}
bool CriticalArea::CheckSpeedHorizontal(quint32 value)
{
    return true;
}

bool CriticalArea::CheckCourse(quint16 value)
{
    return true;
}

bool CriticalArea::CheckTargetType(quint32 value)
{
    return true;
}

bool CriticalArea::CheckTargetModel(QString model)
{
    return true;
}

bool CriticalArea::CheckSystem(quint16 value)
{
    return true;
}

void CriticalArea::StartSideLineFlash()
{

}

void CriticalArea::StopSideLineFlash()
{

}

bool CriticalArea::isAlarming()
{

}
