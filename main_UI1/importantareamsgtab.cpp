#include "importantareamsgtab.h"
#include<QWidget>
#include<QGroupBox>
#include<QLabel>
#include<QComboBox>
#include<QLineEdit>
#include<QPushButton>
#include<QTextEdit>
#include<QCheckBox>
ImportantAreaMsgTab::ImportantAreaMsgTab(QWidget *parent) : QWidget(parent)
{
SetUpUi();

}
void ImportantAreaMsgTab::SetUpUi(){
    //为类中的变量分配空间
    targetAttribute=new QGroupBox(QStringLiteral("目标属性"),this);
    flightStatus=new QGroupBox(QStringLiteral("飞行状态"),this);
    areaAttribute=new QGroupBox(QStringLiteral("区域属性"),this);
    remark=new QGroupBox(QStringLiteral("备注"),this);
    normalOrError=new QLabel(QStringLiteral("区域内状态正常，如果不设置条件，默认就是进入区域就全部报警的标识"),this);
    normalOrError->setStyleSheet("QLabel{font-weight:normal;font-size:20px}");
    flightType=new QLabel(QStringLiteral("飞行器类型"),targetAttribute);
    flightTypeSelect=new QComboBox(targetAttribute);

    flightSpeed=new QLabel(QStringLiteral("航速"),flightStatus);
    flightSpeedMin=new QLineEdit(flightStatus);
    flightSpeedConnect=new QLabel(QStringLiteral("—————"),flightStatus);
    flightSpeedMax=new QLineEdit(flightStatus);
    flightHeight=new QLabel(QStringLiteral("高度"),flightStatus);
    flightHeightMin=new QLineEdit(flightStatus);
    flightHeightConnect=new QLabel(QStringLiteral("—————"),flightStatus);
    flightHeightMax=new QLineEdit(flightStatus);
    verticalLiftRate=new QLabel(QStringLiteral("垂直升降率"),flightStatus);
    verticalLiftRateMin=new QLineEdit(flightStatus);
    verticalLiftRateConnect=new QLabel(QStringLiteral("—————"),flightStatus);
    verticalLiftRateMax=new QLineEdit(flightStatus);
    backgroundColor=new QLabel(QStringLiteral("背景色"),areaAttribute);
    selectColorBtn=new QPushButton(QStringLiteral("选色按钮"),areaAttribute);
    remarkTextEdit=new QTextEdit(remark);

    //目标属性水平布局的添加
    targetAttributeHBox=new QHBoxLayout(this);
    targetAttributeHBox->addWidget(flightType,1);
    targetAttributeHBox->addStretch(2);
    targetAttributeHBox->addWidget(flightTypeSelect,4);
    targetAttributeHBox->addStretch(1);
    targetAttribute->setLayout(targetAttributeHBox);

    //飞行状态栅栏布局
    flightStatusGrid=new QGridLayout(flightStatus);
    flightStatusGrid->addWidget(flightSpeed,0,0);
    flightStatusGrid->setColumnStretch(1,2);
    flightStatusGrid->setColumnStretch(9,1);
    flightStatusGrid->addWidget(flightSpeedMin,0,3,1,2);
    flightStatusGrid->addWidget(flightSpeedConnect,0,5);
    flightStatusGrid->addWidget(flightSpeedMax,0,6,1,2);
    flightStatusGrid->addWidget(flightHeight,1,0);
    flightStatusGrid->addWidget(flightHeightMin,1,3,1,2);
    flightStatusGrid->addWidget(flightHeightConnect,1,5);
    flightStatusGrid->addWidget(flightHeightMax,1,6,1,2);
    flightStatusGrid->addWidget(verticalLiftRate,2,0);
    flightStatusGrid->addWidget(verticalLiftRateMin,2,3,1,2);
    flightStatusGrid->addWidget(verticalLiftRateConnect,2,5);
    flightStatusGrid->addWidget(verticalLiftRateMax,2,6,1,2);

    //区域属性的水平布局
    areaAttributeHBox=new QHBoxLayout(areaAttribute);
    areaAttributeHBox->addWidget(backgroundColor,1);
    areaAttributeHBox->addStretch(2);
    areaAttributeHBox->addWidget(selectColorBtn,4);
    areaAttributeHBox->addStretch(1);
    areaAttribute->setLayout(areaAttributeHBox);

    //备注的垂直布局
    remarkVBox=new QVBoxLayout(this);
    remarkVBox->addWidget(remarkTextEdit);
    remark->setLayout(remarkVBox);

    //重点区域信息的垂直布局
    importAreaInfoVBox=new QVBoxLayout(this);
    importAreaInfoVBox->addWidget(targetAttribute);
    importAreaInfoVBox->addWidget(flightStatus);
    importAreaInfoVBox->addWidget(areaAttribute);
    importAreaInfoVBox->addWidget(remark);
    importAreaInfoVBox->addWidget(normalOrError);

    //颜色选择按钮与showColors()绑定
    connect(selectColorBtn,&QPushButton::clicked,this,&ImportantAreaMsgTab::ShowColors);

}
void ImportantAreaMsgTab::ShowColors(){
    QColor c=QColorDialog::getColor(Qt::blue);
    QString btn_color=tr("QPushButton{background-color:rgb(%1,%2,%3)}").arg(c.red()).arg(c.green()).arg(c.blue());
    selectColorBtn->setStyleSheet(btn_color);

}
