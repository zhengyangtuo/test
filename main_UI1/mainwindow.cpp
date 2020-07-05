#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"importantarea.h"
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
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("警戒条件")<<QStringLiteral("值"));
//       QHeaderView *head=ui->treeWidget->header();
//       head->setSectionResizeMode(QHeaderView::Stretch);

        QString str=tr("QTabWidget QTabBar::tab{width:%1px;height:%2px;font-weight:bold;font-size:20px}").arg(ui->tabWidget->width()*2).arg(50);
        //设置非选择项
        //       str.append("QTabWidget QTabBar::tab:!selected{margin-top:10px;margin-bottom:-10px;color:black}");
//        str.append("QTabWidget QTabBar{width:%1px;height:%2px;font-szie:20px;font-weight:bold}").arg(ui->tabWidget->width()*2).arg(50);

       ui->tabWidget->setStyleSheet(str);
        QLabel *colorlabel=new QLabel(QStringLiteral("背景色"),ui->groupBox_3);

        colorbtn=new QPushButton(ui->groupBox_3);
        colorbtn->setText(QStringLiteral("颜色按钮"));
        colorFrame=new QFrame(ui->groupBox_3);
//        colorFrame->setFrameShape(QFrame::Box);
//        colorFrame->setAutoFillBackground(true);
//        colorFrame->resize(100,50);
        QHBoxLayout *layout=new QHBoxLayout;

        layout->addWidget(colorlabel,1);
        layout->addStretch(2);
        layout->addWidget(colorbtn,4);
        layout->addStretch(1);
//        layout->addWidget(colorSelectLabel);
//        layout->addStretch();
        QVBoxLayout *layoutVbox=new QVBoxLayout;
        layoutVbox->addLayout(layout);
        ui->groupBox_3->setLayout(layoutVbox);
        ui->groupBox_3->setStyleSheet("QGroupBox,QLabel,QPushButton,QComboBox{font-size:18px;font-weight:bold}");
        connect(colorbtn,&QPushButton::clicked,this,&MainWindow::showcolors);


        //创建弹出菜单对象
        pMenu=new QMenu(this);
        QAction *pAction=new QAction(pMenu);
        pAction->setText(QStringLiteral("创建区域"));
        pAction->setIcon(QIcon(""));
        pMenu->addAction(pAction);
        connect(pAction,&QAction::triggered,this,&MainWindow::createArea);

//        QAction *pAction1=new QAction(pMenu);
//        pAction1->setText(QStringLiteral(""));
        connect(ui->tabWidget->tabBar(),&QTabBar::tabBarDoubleClicked,this,&MainWindow::changeTarBarName);
        changeStatusButton=new QCheckBox("",ui->tabWidget);
        //QLabel *text=new QLabel("",ui->tabWidget);
        ui->tabWidget->tabBar()->setTabButton(0,QTabBar::LeftSide,changeStatusButton);

        connect(changeStatusButton,&QCheckBox::toggled,this,&MainWindow::changeStatus);
        //工具栏
        toolBar=addToolBar("mainToolBar");
        actionRectangle=new QAction(QIcon(QPixmap(":/icon/rectangle.png")),"",toolBar);
        actionRound=new QAction(QIcon(":/icon/round.png"),"",toolBar);
        actionEllipse=new QAction(QIcon(":/icon/ellipse.png"),"",toolBar);
        toolBar->addAction(actionRectangle);
        toolBar->addAction(actionRound);
        toolBar->addAction(actionEllipse);
        connect(actionRectangle,&QAction::triggered,this,&MainWindow::createArea);
        connect(actionRound,&QAction::triggered,this,&MainWindow::createArea);
        connect(actionEllipse,&QAction::triggered,this,&MainWindow::createArea);

        }
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showcolors(){
    QColor c=QColorDialog::getColor(Qt::blue);
//    QPalette palette;

//    palette.setColor(QPalette::Background, c);

//    if(c.isValid()){
//        colorbtn->setPalette(palette);
//    }
    QString btn_color=tr("QPushButton{background-color:rgb(%1,%2,%3)}").arg(c.red()).arg(c.green()).arg(c.blue());
//    qDebug()<<tr("%1,%2,%3").arg(c.red()).arg(c.green()).arg(c.blue());
    colorbtn->setStyleSheet(btn_color);

}

void MainWindow::createArea(){
    bool ok;
    int index=ui->tabWidget->currentIndex()+1;
    QString str=QInputDialog::getText(this,QStringLiteral("创建"),QStringLiteral("请输入区域名"),QLineEdit::Normal,"",&ok);
    if(ok&&str!=""){
        QCheckBox *statusBtn=new QCheckBox(ui->tabWidget->tabBar());
        ImportantArea *w=new ImportantArea(this);
        ui->tabWidget->insertTab(index,w,str);
        ui->tabWidget->tabBar()->setTabButton(index,QTabBar::LeftSide,statusBtn);
        ui->tabWidget->tabBar()->setTabTextColor(index,QColor(255,0,0));
        connect(statusBtn,&QCheckBox::toggled,this,&MainWindow::changeStatus);


    }

//为什莫指针可以，但是实例化却不行
//    ImportantArea w;
//    w.setParent(ui->tabWidget);
//    ui->tabWidget->insertTab(2,&w,QStringLiteral("区域3"));

}

//鼠标事件响应函数
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton){
        //下面执行弹出操作
        pMenu->popup(event->globalPos());
    }
}
void MainWindow::changeStatus(bool checked){
    //获得发出者
    QCheckBox *signalSender=qobject_cast<QCheckBox*>(sender());
//    singalSender->hide();

    int index=ui->tabWidget->tabBar()->tabAt(QPoint(signalSender->x(),signalSender->y()));
//    qDebug()<<index<<signalSender->parentWidget()->metaObject()->className();
//输入yes就可以修改状态
    bool ok;
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
            disconnect(signalSender,&QCheckBox::toggled,this,&MainWindow::changeStatus);
            signalSender->setChecked(true);
            connect(signalSender,&QCheckBox::toggled,this,&MainWindow::changeStatus);

        }else{
            signalSender->setCheckable(false);
            signalSender->setCheckable(true);
        }
    }


//消息框
//    QMessageBox msgBox;
//    msgBox.setText(QStringLiteral("区域的状态被修改"));
//    msgBox.setInformativeText(QStringLiteral("你想要保存这个修改吗？"));
//    msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Cancel);
//    msgBox.setDefaultButton(QMessageBox::Save);
//    int ret=msgBox.exec();
//*    QMessageBox::question(this,"changeStatus",QStringLiteral("确定修改本区域状态"));
//    if(!checked&&ret==QMessageBox::Save){
//    ui->tabWidget->tabBar()->setTabTextColor(index,QColor(255,0,0));
//*        ui->tabWidget->currentWidget()->setStyleSheet("QTabBar::tab{background-color:#a7ab9b}");
//            //->setStyleSheet("QTabBar::tab{background-color:#a7ab9b}");
//*        ui->tabWidget->tabBar()->setStyleSheet("QTabWidget:tab-bar{background-color:#a7ab9b}");
//    }else if(!checked&&ret==QMessageBox::Cancel)
//    {
//        changeStatusButton->setChecked(true);

//    }else if(checked&&ret==QMessageBox::Save){
//        ui->tabWidget->tabBar()->setTabTextColor(index,QColor(0,0,0));
// *      ui->tabWidget->currentWidget()->setStyleSheet("QTabBar::tab{background-color:rgb(255,255,255)}");
// *   ui->tabWidget->tabBar()->setStyleSheet("QTabBar::tab{background-color:rgb(255,255,255)}");
// *       ui->tabWidget->tabBar()->setStyleSheet("QTabWidget:tab-bar{background-color:rgb(255,255,255)}");
//    }else{
//        changeStatusButton->setCheckable(false);
//        changeStatusButton->setCheckable(true);
//    }


}

void MainWindow::changeTarBarName(){
    bool ok;
    int index=ui->tabWidget->currentIndex();
    QString str=QInputDialog::getText(this,QStringLiteral("修改"),QStringLiteral("修改区域名称"),QLineEdit::Normal,ui->tabWidget->tabText(index),&ok);
    if(ok&&!str.isEmpty()){
        ui->tabWidget->setTabText(index,str);
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
//    int ret=QMessageBox::question(this,QStringLiteral("关闭窗口"),QStringLiteral("确定要删除此区域吗？"),QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Save);
//    switch (ret){
//    case QMessageBox::Save:
//        ui->tabWidget->removeTab(index);
//        break;
//    case QMessageBox::Cancel:
//        break;
//    default:
//        break;

//    }

    bool ok;
    QString str=QInputDialog::getText(this,QStringLiteral("关闭区域"),QStringLiteral("关闭此区域请输入yes"),QLineEdit::Normal,"",&ok);
    if(ok&&str=="yes"){
        ui->tabWidget->removeTab(index);
    }

}
