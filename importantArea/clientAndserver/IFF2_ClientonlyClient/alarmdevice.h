#ifndef ALARMDEVICE_H
#define ALARMDEVICE_H


class AlarmDevice
{
public:
    AlarmDevice();

    //声音报警
    void TurnonAlarm();

    void TurnoffAlarm();

    //闪烁报警
    void TurnonFlash();

    void TurnoffFlash();

    //是否处于报警状态
    bool IsAlarming();

    bool IsFlashing();
};

#endif // ALARMDEVICE_H
