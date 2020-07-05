#ifndef CRITICALAREA_H
#define CRITICALAREA_H

#include<QString>
#include<QPoint>
#include<QGeometry>
#include<QVector>
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
    bool CheckAltitude(quint32 value);

    //检测垂直速度是否异常
    bool CheckSpeedVertical(quint32 value);

    //检测水平速度是否相同
    bool CheckSpeedHorizontal(quint32 value);

    //检测航向是否正常
    bool CheckCourse(quint16 value);

    //检测是否是禁止类型
    bool CheckTargetType(quint32 value);

    //检测是否是禁止型号
    bool CheckTargetModel(QString model);

    //检测是否是禁止体制
    bool CheckSystem(quint16 value);

    //边线闪烁报警状态
    void StartSideLineFlash();

    void StopSideLineFlash();

    //判断是否处于报警转台
    bool isAlarming();

private:

    quint16 ID;//区域ID

    QGeometry shape;//区域形状

    quint32 targetTypes;//禁止类型

    QVector<QString> targetModels;//禁止类型

    quint32 altitude_min;//高度最小允许值

    quint32 altitude_max;//高度最大允许值

    quint32 speedVertical_min;//垂直速度最小允许值

    quint32 speedVertical_max;//垂直速度最大允许值

    quint16 speedHorizontal_min;//水平速度最小允许值

    quint16 speedHorizontal_max;//水平速度最大允许值

    quint16 course_begin;//航向允许起始向

    quint16 course_end;//航向允许结束向

    quint16 system;//体制

    quint16 mode;//模式

    qint8 status;//状态标志

    qint8 isDeleted;//删除标志





};

#endif // CRITICALAREA_H
