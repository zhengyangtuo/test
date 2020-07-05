#ifndef IMPORTANTAREAMAINUI_H
#define IMPORTANTAREAMAINUI_H

#include <QMainWindow>
#include<QPushButton>
#include<QFrame>
#include<QMenu>
#include<QLabel>
#include<QComboBox>
#include<QRadioButton>
#include<QCheckBox>
#include<QToolBar>
#include<QIcon>
namespace Ui {
class ImportantAreaMainUi;
}
/* *
 * 类说明:该类是重点区域主界面的类，初始化重点区域主界面，有新建区域，更改区域的状态以及区域信息，修改标题等功能
 * 使用实例:
 * ImportantAreaMainUi w;
 * w.show();
* */
class ImportantAreaMainUi : public QMainWindow
{
    Q_OBJECT

public:
    /*
     * 函数功能:构造函数，对界面进行初始化
     * 调用表:
     * 输入参数:父指针
     * 输出参数:无
     * 返回值:无
    */
    explicit ImportantAreaMainUi(QWidget *parent = nullptr);
    /*
     * 函数功能:析构函数，释放界面的空间
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    ~ImportantAreaMainUi();
    /*
     * 函数功能:为类中的变量分配空间，并进行属性的设置
     * 调用表:无
     * 被调用表:在构造函数中被调用
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void SetUpUi();
    /*
     * 函数功能:重写鼠标事件响应函数，当右击时会弹出菜单
     * 绑定表:自动生成的信号与connect
     * 调用表:无
     * 被调用表:自动生成
     * 输入参数:鼠标事件的指针
     * 输出参数:无
     * 返回值:无
    */
    void mousePressEvent(QMouseEvent *event) override;
    /*
     * 函数功能:添加信号与槽的connect函数
     * 调用表:无
     * 被调用表:构造函数
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void AddConnect();

public slots:
    /*
     * 函数功能:在重点区域的信息界面上新建重点区域
     * 绑定表:与工具栏的每一个triggered()信号绑定
     * 调用表:无
     * 被调用表:自动生成
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void CreateArea();//创建区域
    /*
     * 函数功能:点击tabWidget的中tab的标题栏的选择框切区域的状态
     * 绑定表:与相应tab的toggled(bool checked)信号绑定，connect函数位于CreateArea()在每一
     区域新建时绑定
     * 调用表:无
     * 被调用表:自动生成
     * 输入参数:checked来表示该选择框是否选定
     * 输出参数:无
     * 返回值:无
    */
    void ChangeStatus(bool checked);//改变状态
    /*
     * 函数功能: 双击tab的标题栏修改标题
     * 绑定表:与tabBarDoubleClicked()信号绑定，connect函数位于AddConnect()中
     * 调用表:无
     * 被调用表:自动生成
     * 输入参数:无
     * 输出参数:无
     * 返回值:无
    */
    void ChangeTarBarName();//改变标题文字
private slots:
    /*
     * 函数功能:点击标题栏的删除按钮删除该区域
     * 绑定表:由ui中的删除按钮转到槽生成，connect函数也自动生成
     * 调用表:无
     * 被调用表:自动生成
     * 输入参数:该删除按钮位于tab的序号
     * 输出参数:无
     * 返回值:无
    */
    void on_tabWidget_tabCloseRequested(int index);//关闭标签页

private:
    Ui::ImportantAreaMainUi *ui;

    QPushButton *colorbtn;//第一个界面的颜色按钮

    QMenu *pMenu;//鼠标右键点击出现的菜单

    QComboBox *normalOrError;//在每第一个tab最下端中显示区域状态的信息

    QToolBar *toolBar;//工具栏

    QAction  *actionRectangle;//矩形

    QAction *actionRound;//圆形

    QAction *actionEllipse;//椭圆



};

#endif // MAINWINDOW_H
