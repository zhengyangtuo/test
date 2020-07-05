#include "importantareamainui.h"
#include "ui_importantareamainui.h"
#include"importantareamsgtab.h"
#include<QStringList>
#include<QColor>
#include<QColorDialog>
#include<QPushButton>
#include<QDebug>
#include<QPalette>
#include<QMessageBox>
#include<QMouseEvent>
#include<QInputDialog>
#include<QLineEdit>
#include<QDir>
#include<QRadioButton>
#include<QMessageBox>
ImportantAreaMainUi::ImportantAreaMainUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImportantAreaMainUi)
{

    ui->setupUi(this);
    //初始化函数
    SetUpUi();
    //添加部分的信号与槽
    AddConnect();

}
ImportantAreaMainUi::~ImportantAreaMainUi()
{
    delete ui;
}

void ImportantAreaMainUi::SetUpUi()
{
    //设置tabWidget的tab的属性
    QString str=tr("QTabWidget QTabBar::tab{width:%1px;height:%2px;font-weight:bold;font-size:20px}").arg(ui->tabWidget->width()*2).arg(50);
    ui->tabWidget->setStyleSheet(str);

    //创建弹出菜单对象
    pMenu=new QMenu(this);
    auto *pAction=new QAction(pMenu);
    pAction->setText(QStringLiteral("创建区域"));
    pAction->setIcon(QIcon(""));
    pMenu->addAction(pAction);
    connect(pAction,&QAction::triggered,this,&ImportantAreaMainUi::CreateArea);


    //工具栏
    toolBar=addToolBar("mainToolBar");
    actionRectangle=new QAction(QIcon(QPixmap(":/icon/rectangle.png")),"",toolBar);
    actionRound=new QAction(QIcon(":/icon/round.png"),"",toolBar);
    actionEllipse=new QAction(QIcon(":/icon/ellipse.png"),"",toolBar);
    toolBar->addAction(actionRectangle);
    toolBar->addAction(actionRound);
    toolBar->addAction(actionEllipse);
}

void ImportantAreaMainUi::AddConnect()
{
    //将标题栏的双击信号与更改标题姓名的函数绑定起来
    connect(ui->tabWidget->tabBar(),&QTabBar::tabBarDoubleClicked,this,&ImportantAreaMainUi::ChangeTarBarName);
    //将三个不同形状的新建控件的触发信号与新建区域的函数绑定起来
    connect(actionRectangle,&QAction::triggered,this,&ImportantAreaMainUi::CreateArea);
    connect(actionRound,&QAction::triggered,this,&ImportantAreaMainUi::CreateArea);
    connect(actionEllipse,&QAction::triggered,this,&ImportantAreaMainUi::CreateArea);

}

void ImportantAreaMainUi::CreateArea(){
    bool ok;
    //获取目前tabWidget中含有的tab数量
    int index=ui->tabWidget->count();
    //弹出输入框来获取区域名称
    QString str=QInputDialog::getText(this,QStringLiteral("创建"),QStringLiteral("请输入区域名"),QLineEdit::Normal,"",&ok);
    //当输入区域名不为空且点击ok后才能将新建区域的tab插入到最后一位
    if(ok&&str!=""){
        auto *statusBtn=new QCheckBox(ui->tabWidget->tabBar());
        auto *w=new ImportantAreaMsgTab(this);
        ui->tabWidget->insertTab(index,w,str);
        ui->tabWidget->tabBar()->setTabButton(index,QTabBar::LeftSide,statusBtn);
        ui->tabWidget->tabBar()->setTabTextColor(index,QColor(255,0,0));
        connect(statusBtn,&QCheckBox::toggled,this,&ImportantAreaMainUi::ChangeStatus);


    }

//为什莫指针可以，但是实例化却不行
//    ImportantArea w;
//    w.setParent(ui->tabWidget);
//    ui->tabWidget->insertTab(2,&w,QStringLiteral("区域3"));

}

//鼠标事件响应函数
void ImportantAreaMainUi::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){
        //下面执行弹出操作
        pMenu->popup(event->globalPos());
    }
}
void ImportantAreaMainUi::ChangeStatus(bool checked){
    //获得信号发出者
    auto *signalSender=qobject_cast<QCheckBox*>(sender());
    //获取信号发出者的序号
    int index=ui->tabWidget->tabBar()->tabAt(QPoint(signalSender->x(),signalSender->y()));

    bool ok;
    //弹出输入框，输入yes就可以修改状态，其他情况都要返回原来的状态
    QString str=QInputDialog::getText(this,QStringLiteral("区域状态"),QStringLiteral("确定修改状态请输入yes"),QLineEdit::Normal,"",&ok);
    if(ok&&str=="yes"){
        if(!checked){
         ui->tabWidget->tabBar()->setTabTextColor(index,QColor(255,0,0));
        }else{
         ui->tabWidget->tabBar()->setTabTextColor(index,QColor(0,0,0));
        }

    }else{
        if(!checked){
            //需要断开信号与槽的链接，否则会出现setChecked()会调用toggled信号，会再调用一次槽函数。
            disconnect(signalSender,&QCheckBox::toggled,this,&ImportantAreaMainUi::ChangeStatus);
            signalSender->setChecked(true);
            connect(signalSender,&QCheckBox::toggled,this,&ImportantAreaMainUi::ChangeStatus);

        }else{
            signalSender->setCheckable(false);
            signalSender->setCheckable(true);
        }
    }

}

void ImportantAreaMainUi::ChangeTarBarName(){
    bool ok;
    //获取当前的tab的序号
    int index=ui->tabWidget->currentIndex();
    //输入框输入新的区域名，点击ok且新区域名不为空时才能修改区域名
    QString str=QInputDialog::getText(this,QStringLiteral("修改"),QStringLiteral("修改区域名称"),QLineEdit::Normal,ui->tabWidget->tabText(index),&ok);
    if(ok&&!str.isEmpty()){
        ui->tabWidget->setTabText(index,str);
    }
}

void ImportantAreaMainUi::on_tabWidget_tabCloseRequested(int index)
{
    bool ok;
    //当输入框输入yes且点击ok时才能删除该区域，其他情况则不做修改
    QString str=QInputDialog::getText(this,QStringLiteral("关闭区域"),QStringLiteral("关闭此区域请输入yes"),QLineEdit::Normal,"",&ok);
    if(ok&&str=="yes"){
        ui->tabWidget->removeTab(index);
    }

}
