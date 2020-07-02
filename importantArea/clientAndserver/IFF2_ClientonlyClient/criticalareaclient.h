#ifndef CRITICALAREACLIENT_H
#define CRITICALAREACLIENT_H
#include<QString>
#include<QColor>
class CriticalAreaClient
{
public:
    CriticalAreaClient();

    //重点区域形状和颜色
    void SetGeometry(QString Geo,QString col);

    //将重点区域绘制到图层
    bool DrawCriticalAreaToMap();

    //重点区域是否有效
    bool IsActive();

    //设置选中状态
    void HightLight();

    //去除选调状态
    void DeHightLight();

private:
    QString name;//区域名称

    quint16 ID;//区域ID

    QString Geometry;//区域形状

    QColor color;//区域颜色

    QString remarks;//区域注释

    bool isActive;//有效标志

    bool isHightLight;//高亮标志





};

#endif // CRITICALAREACLIENT_H
