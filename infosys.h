#ifndef INFOSYS_H
#define INFOSYS_H

#include <QDialog>
#include <QPointer>
#include <vector>
#include <company.h>
#include <query.h>
#include "allquery.h"
#include "modify.h"
#include "delete.h"
#include "pushin.h"

QT_BEGIN_NAMESPACE
// 前向声明，生成UI界面的类
namespace Ui {
    class InfoSys;
}
QT_END_NAMESPACE

// InfoSys类：信息管理系统的主界面
class InfoSys : public QDialog
{
    Q_OBJECT

public:
    // 各个功能的窗口对象
    Query *query=NULL;
    AllQuery *allQuery=NULL;
    Modify *modify=NULL;
    Delete *del=NULL;
    Pushin *pushin=NULL;

    // 员工信息存储容器
    vector<QPointer<Company>>employee;
    // 构造函数
    InfoSys(QWidget *parent = nullptr);
    // 析构函数
    ~InfoSys();

private:
    // 指向UI界面对象的指针
    Ui::InfoSys *ui;

private slots:
    // 槽函数，分别响应不同按钮的点击事件
    void on_p1button_clicked();
    void on_p2button_clicked();
    void on_p3button_clicked();
    void on_p4button_clicked();
    void on_p5button_clicked();
    void on_p6button_clicked();
};
#endif // INFOSYS_H
