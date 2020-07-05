#include "importarea.h"
#include<QVector>
#include<QDataStream>
importArea::importArea()
{
//测试
type=messageType::importantAreaError;
importantAreaNum=2;
importantAreaId.append(5);
importantAreaId.append(10);
}

QDataStream& operator>>(QDataStream &inStream,importArea &msg){
    //将重点区域异常的信息写入变量中
    quint16 type;
    inStream>>type;
    msg.setMessageType(type);
    quint16 num;
    inStream>>num;
    msg.setImportantAreaNum(num);
    QVector <quint16> id;
    inStream>>id;
    msg.setImportantAreaId(id);

    return inStream;
}

QDataStream& operator<<(QDataStream &outStream,const importArea &msg){
    //将重点区域异常的信息写入流中
    outStream<<msg.type;

    outStream<<msg.importantAreaNum;

    outStream<<msg.importantAreaId;

    return outStream;
}

quint16 importArea::getImportantAreaNum(){

    return importantAreaNum;

}
void importArea::setImportantAreaNum(quint16 value){
    importantAreaNum=value;
}

QVector<quint16> importArea::getImportantAreaId(){
    return importantAreaId;

}
void importArea::setImportantAreaId(const QVector<quint16> id){
    importantAreaId=id;

}
quint16 importArea::getMessageType(){
    return type;
}
void importArea::setMessageType(quint16 value){
    type=value;
}


