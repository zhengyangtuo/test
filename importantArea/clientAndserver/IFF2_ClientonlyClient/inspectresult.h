#ifndef INSPECTRESULT_H
#define INSPECTRESULT_H
#include<QMainWindow>

class InspectResult
{
public:
    InspectResult();

    //警报级别
    quint16 ExceptionLevel();

    //经过了哪个重点区域
    QString CriticalArea();

    /*飞行器参数检测结果*/
    //高度是否正常
    bool IsAltitudeNormal();

    //垂直速度是否正常
    bool IsSpeedVerticalNormal();

    //水平速度是否正常
    bool IsSpeedHorizontalNormal();

    //航向是否正常
    bool IsCourseNormal();

    //是否是禁止类型
    bool HasTargetTypeException();

    //是否是禁止型号
    bool HasTargetModelException();

    //模式是否正产
    bool IsModeNormal();

    //体制是否正常
    bool IsSystemNormal();
private:
    bool altitudeFlag; //高度检测的结果

    bool speedVerticalFlag;//垂直速度检测结果

    bool speedHorizontalFlag;//水平速度检测结果

    bool courseFlag;//航向的检测结果

    bool targetTypeFlag;//是否是禁止类型的检测结果

    bool targetModelFlag;//是否是禁止型号的检测结果

    bool systemFlag;//体制的检测结果

    bool modeFlag;//

};

#endif // INSPECTRESULT_H
