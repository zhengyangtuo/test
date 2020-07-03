#ifndef CRITICALAREAMANAGER_H
#define CRITICALAREAMANAGER_H
#include"criticalarea.h"
#include<QVector>
#include<QMap>
class CriticalAreaManager
{
public:
    CriticalAreaManager();

    //新建一个重点区域
    bool AddNewArea(CriticalArea area);

    //通过名称删除一个重点区域
    bool DeleteArea(QString name);

    //更新重点区域
    bool UpdateCriticalArea(CriticalArea area);

    //通过名称获取重点区域引用
    CriticalArea GetCriticalArea(QString name);

    //开机初始化
    bool DownloadCriticalAreasFromDatabase();

    //关机清理资源
    bool CloseAllCriticalAreas();

    /*飞行器参数检测*/
    void InspectFlight(flightinfo& info,QVector<InspectResult&> result);


private:
    /*内存中的重点区域*/
    QMap<QString,CriticalArea> criticalAreas;





};

#endif // CRITICALAREAMANAGER_H
