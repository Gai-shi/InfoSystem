#ifndef ALLQUERY_H
#define ALLQUERY_H

#include <QWidget>
#include <QPointer>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "company.h"

// 命名空间 Ui，UI设计器生成的界面类Allquery的定义
namespace Ui {
    class Allquery;
}

// Allquery类：用于实现员工信息的查询界面
class AllQuery : public QWidget
{
    Q_OBJECT

public:
    // 用于存储所有员工信息的向量容器
    std::vector<QPointer<Company>>allv;
    // 获取员工信息的向量并根据需要保存到文件
    void getvector(std::vector<QPointer<Company>>&tem,bool saveInfo=false);
    // Allquery构造函数
    explicit AllQuery(QWidget *parent = nullptr);
    // Allquery析构函数
    ~AllQuery();

signals:
    // backallquery 用于通知界面返回到主查询界面
    void backallquery();

private slots:
    // on_btnallback_clicked 槽函数响应"查看所有员工信息"按钮的点击事件
    void on_btnallback_clicked();

private:
    // 指向UI设计器生成的Allquery类的指针
    Ui::Allquery *ui;
};

#endif // ALLQUERY_H
