#ifndef IMPORTANTAREA_H
#define IMPORTANTAREA_H

#include <QWidget>
#include<QGroupBox>
#include<QLabel>
#include<QComboBox>
#include<QLineEdit>
#include<QPushButton>
#include<QTextEdit>
#include<QCheckBox>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QColorDialog>
class ImportantArea : public QWidget
{
    Q_OBJECT
public:
    explicit ImportantArea(QWidget *parent = nullptr);
    void setupUI();//对控件的初始化
signals:

public slots:
    void showColors();

private:
    QCheckBox *statusChangeBtn;//区域有效性切换按钮

    QGroupBox *targetAttribute;//目标属性

    QGroupBox *flightStatus;//飞行状态

    QGroupBox *areaAttribute;//区域属性

    QGroupBox *remark;//备注

    QLabel *normalOrError;//上述属性正常或异常

    QLabel *flightType;//飞行器类型

    QComboBox *flightTypeSelect;//飞行器选择框

    QHBoxLayout *targetAttributeHBox;//目标属性的水平布局

    QLabel *flightSpeed;//航速

    QLineEdit *flightSpeedMin;//最小航速

    QLabel *flightSpeedConnect;//航速连接线

    QLineEdit *flightSpeedMax;//最大航速

    QLabel *flightHeight;//高度

    QLineEdit *flightHeightMin;//最小高度

    QLabel *flightHeightConnect;//高度连接线

    QLineEdit *flightHeightMax;//最大高度

    QLabel *verticalLiftRate;//垂直升降率

    QLineEdit *verticalLiftRateMin;//垂直升降率最小值

    QLabel *verticalLiftRateConnect;//垂直升降率连接线

    QLineEdit *verticalLiftRateMax;//垂直升降率最大值

    QGridLayout *flightStatusGrid;//飞行状态的栅栏布局

    QLabel *backgroundColor;//背景色

    QPushButton *selectColorBtn;//选择颜色的按钮

    QHBoxLayout *areaAttributeHBox;//区域属性的水平布局

    QTextEdit *remarkTextEdit;//备注文本

    QVBoxLayout *remarkVBox;//备注的水平布局

    QVBoxLayout *importAreaInfoVBox;//重点区域信息的垂直布局

};

#endif // IMPORTANTAREA_H
