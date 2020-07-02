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
    importArea();

    friend QDataStream& operator>>(QDataStream &inStream,importArea &msg);

    friend QDataStream& operator<<(QDataStream &outStream,const importArea& msg);

    quint16 getImportantAreaNum();

    void setImportantAreaNum(quint16 value);

    QVector<quint16> getImportantAreaId();

    void setImportantAreaId(QVector<quint16> id);

    quint16 getMessageType();

    void setMessageType(quint16 value);


private:
    quint16 type;//报文类型

    quint16 importantAreaNum;//区域的数目

    QVector<quint16> importantAreaId;//区域的id






};

#endif // IMPORTAREA_H
