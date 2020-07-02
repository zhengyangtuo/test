#include "criticalareaclient.h"

CriticalAreaClient::CriticalAreaClient()
{

}
void  CriticalAreaClient::SetGeometry(QString Geo,QString col){
    Geometry=Geo;

    color=col;

}
bool CriticalAreaClient::DrawCriticalAreaToMap(){

return true;
}

bool CriticalAreaClient::IsActive(){

    return isActive;
}

void  CriticalAreaClient::HightLight(){
    isHightLight=true;
}

void   CriticalAreaClient::DeHightLight(){
    isHightLight=false;

}

