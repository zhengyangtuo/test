#ifndef CRITICALAREAMANAGERCLIENT_H
#define CRITICALAREAMANAGERCLIENT_H
#include"criticalareaclient.h"
#include<QMap>

class CriticalAreaManagerClient
{
public:
    CriticalAreaManagerClient();

    //新建重点区域
    bool AddNewArea(CriticalAreaClient criticalArea);

    //删除重点区域
    bool DeleteArea(QString name);

    //更新重点区域
    bool UpdateCriticalArea(CriticalAreaClient criticalArea);

    //通过名字获取重点区域引用
    CriticalAreaClient GetCriticalArea(QString name);

    /*初始化*/
    //开机初始化
    bool DownLoadCriticalAreas();

    //关机清理资源
    void ColseAllCriticalAreas();

    /*监听服务端的信息*/
    void Listening();
 private:
    //重点区域内存数据
    QMap<QString,CriticalAreaClient> CriticalAreas;



};

#endif // CRITICALAREAMANAGERCLIENT_H
