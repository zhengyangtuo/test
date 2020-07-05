#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
public slots:
    void showcolors();//显示选择颜色
    void createArea();//创建区域
    void changeStatus(bool checked);//改变状态
    void changeTarBarName();//改变标题文字
private slots:
    void on_tabWidget_tabCloseRequested(int index);//关闭标签页

private:
    Ui::MainWindow *ui;
    QPushButton *colorbtn;
    QFrame *colorFrame;
    QMenu *pMenu;
    QLabel *valid;
    QComboBox *normalOrError;
    QCheckBox *changeStatusButton;//改变区域的状态
    QToolBar *toolBar;//工具栏
    QAction  *actionRectangle;//矩形
    QAction *actionRound;//圆形
    QAction *actionEllipse;//椭圆



};

#endif // MAINWINDOW_H
