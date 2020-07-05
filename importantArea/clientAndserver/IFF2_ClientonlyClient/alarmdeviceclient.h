#ifndef ALARMDEVICECLIENT_H
#define ALARMDEVICECLIENT_H
#include"criticalareaclient.h"

class AlarmDeviceClient
{
public:
    AlarmDeviceClient();

    //声音报警
    void TurnonAlarm();

    void TurnoffAlarm();

    //闪烁报警
    void TurnonFlash(CriticalAreaClient &area);

    void TurnoffFlash(CriticalAreaClient &area);

    //是否处于报警状态
    bool IsAlarming(CriticalAreaClient &area);

    bool IsFlashing(CriticalAreaClient &area);




};

#endif // ALARMDEVICECLIENT_H
