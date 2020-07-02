#ifndef CRITICALAREA_H
#define CRITICALAREA_H

#include<QString>
#include<QPoint>
class CriticalArea
{
public:
    CriticalArea();

    //设置区域形状
    void SetGeometry(QString Geometry);

    //判断重点区域是否有效
    bool IsActive();

    /*警戒条件检测*/
    //飞行器是否在该区域
    bool Contains(QPoint pos);

    //检测高度是否正常
    bool CheckAltitude(quint32);

    //


};

#endif // CRITICALAREA_H
