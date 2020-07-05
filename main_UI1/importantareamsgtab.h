#ifndef IMPORTANTAREAMSGTAB_H
#define IMPORTANTAREAMSGTAB_H

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

/* *
 * 类说明:本类主要针对重点区域信息的UI界面的tabWidget中每一个tab设置的控件，用于在新建区域时在
 * 界面上显示与之前相同的重点区域信息的UI界面。
 * 使用实例:
 * auto *w=new ImportantArea(this);//声明该类对象
 * tabWidget->insertTab(index,w,str); //向标签页中index位置上插入标题为str的ImportantArea类对象
* */
class ImportantAreaMsgTab : public QWidget
{
    Q_OBJECT
public:
    /*
     * 函数功能:构造函数，对新建区域的tab控件进行初始化
     * 调用表:调用SetUpUi函数
     * 输入参数:父指针
     * 输出参数:无
     * 返回值:无
    */
    explicit ImportantAreaMsgTab(QWidget *parent = nullptr);
    /*
     * 函数功能:对类中的变量分配空间，且对设置布局
     * 调用表:无
     * 被调用表:被构造函数调用
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void SetUpUi();//对控件的初始化
signals:

public slots:
    /*
     * 函数功能:点击选择颜色按钮后出现颜色选择框选择颜色，并将颜色显示在按钮的背景色
     * 绑定表:与该槽函数绑定的是按钮的clicked()信号，connect函数在构造函数中
     * 调用表:无
     * 被调用表:自动生成
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void ShowColors();//显示选择颜色

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

#endif // IMPORTANTAREAMSGTAB_H
