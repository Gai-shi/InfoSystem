#ifndef PUSHIN_H
#define PUSHIN_H

#include <QWidget>
#include <QPointer>
#include "company.h"

// 生成ui界面
namespace Ui {
    class Pushin;
}

// Pushin类：用于处理员工信息的新增功能
class Pushin : public QWidget
{
    Q_OBJECT

public:
    // 数据容器指针，用于新增员工信息
    std::vector<QPointer<Company>>*pushv=nullptr;
    // 接收数据容器
    void getvector(std::vector<QPointer<Company>>&tem);

    // 构造函数
    explicit Pushin(QWidget *parent = nullptr);
    // 析构函数
    ~Pushin();

signals:
    // 返回主页面
    void backpushin();

private:
    // 生成ui对象
    Ui::Pushin *ui;

private slots:
    // 触发各信号的槽函数
    void on_Pushinbtn_clicked();
    void on_btnpushback_clicked();
};

#endif // PUSHIN_H
