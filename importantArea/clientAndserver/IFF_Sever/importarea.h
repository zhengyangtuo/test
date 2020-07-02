#ifndef IMPORTAREA_H
#define IMPORTAREA_H
#include<QDataStream>
#include<QVector>
enum messageType{
    importantAreaError=1,
    createImportantArea=2,
    updateImportantArea=3,
    deleteImportantArea=4
};
class importArea
{
public:
    /*
     * 函数功能:构造函数
     * 调用表:无
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    importArea();
    /*
     * 函数功能:重载输入运算符来实现反序列化
     * 调用表:无
     * 输入参数:序列化数据以及将反序列化数据存储所需要的重点区域类对象的地址
     * 输出参数:
     * 返回值:
    */
    friend QDataStream& operator>>(QDataStream &inStream,importArea &msg);
    /*
     * 函数功能:重载输出运算符来实现序列化
     * 调用表:无
     * 输入参数:序列化数据以及需要序列化的重点区域类对象
     * 输出参数:序列化后的QDataStream
     * 返回值:序列化后的QDataStream
    */
    friend QDataStream& operator<<(QDataStream &outStream,const importArea& msg);
    /*
     * 函数功能:获取重点区域的数目
     * 调用表:无
     * 被调用表:在mainwindow中的ReceiveMsg()中调用
     * 输入参数:无
     * 输出参数:重点区域的数目
     * 返回值:重点区域的数目
    */
    quint16 getImportantAreaNum();

    /*
     * 函数功能:为类中变量importantAreaNum赋值
     * 调用表:无
     * 被调用表:在重载输出运算符中
     * 输入参数:重点区域的数目
     * 输出参数:无
     * 返回值:无
    */
    void setImportantAreaNum(quint16 value);

    /*
     * 函数功能:获取重点区域的id数组
     * 调用表:无
     * 被调用表:在mainwindow中的ReceiveMsg()中调用
     * 输入参数:无
     * 输出参数:重点区域id的数组
     * 返回值:无
    */
    QVector<quint16> getImportantAreaId();
    /*
     * 函数功能:为类中变量importantAreaId赋值
    */
    void setImportantAreaId(const QVector<quint16> id);

    quint16 getMessageType();

    void setMessageType(quint16 value);


private:
    quint16 type;

    quint16 importantAreaNum;
    QVector<quint16> importantAreaId;
};

#endif // IMPORTAREA_H
