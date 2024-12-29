#ifndef MODIFY_H
#define MODIFY_H

#include <QWidget>
#include <QPointer>
#include "company.h"

// 生成ui界面
namespace Ui {
    class Modify;
}

// Modify类：提供修改员工信息的界面功能
class Modify : public QWidget
{
    Q_OBJECT

public:
    // 存储员工对象指针的容器，用于修改操作
    std::vector<QPointer<Company>>modv;
    // 传递员工数据
    void getvector(std::vector<QPointer<Company>>&tem);
    // 构造函数
    explicit Modify(QWidget *parent = nullptr);
    // 析构函数
    ~Modify();

signals:
    // 信号：返回主界面
    void backmodify();

private:
    // 指向自动生成的UI对象的指针
    Ui::Modify *ui;

private slots:
    // 槽函数，分别处理按钮点击事件
    void on_MEnsurebtn_clicked();
    void on_MSalarybtn_clicked();
    void on_btnmodback_clicked();
};

#endif // MODIFY_H
