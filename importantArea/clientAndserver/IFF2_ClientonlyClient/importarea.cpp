#include "importarea.h"
#include<QVector>
importArea::importArea()
{
//测试
type=messageType::importantAreaError;
importantAreaNum=2;
importantAreaId.append(5);
importantAreaId.append(10);
}

QDataStream& operator>>(QDataStream &inStream,importArea &msg){
    //测试直接对类输出出现问题
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
void importArea::setImportantAreaId(QVector<quint16> id){
//下面的添加不会对之前的数据删除
//    for(const auto &i:id){
//        importantAreaId.append(i);
//    }
    importantAreaId=id;

}

quint16 importArea::getMessageType(){
    return type;
}
void importArea::setMessageType(quint16 value){
    type=value;
}
