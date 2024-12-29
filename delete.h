#ifndef DELETE_H
#define DELETE_H

#include <QWidget>
#include <QPointer>
#include <QDebug>
#include "company.h"

// 命名空间 Ui：包含自动生成的UI界面类声明
namespace Ui {
    class Delete;
}

// Delete类：用于处理员工删除的界面
class Delete : public QWidget
{
    Q_OBJECT

public:
    // delv: 存储员工对象指针的vector，用于存储当前待删除的员工信息列表，默认值为空
    std::vector<QPointer<Company>>*delv=nullptr;
    //  获取一个vector的引用，传入的vector用于更新delv
    void getvector(std::vector<QPointer<Company>>&tem);

    // 构造函数：初始化Delete界面
    explicit Delete(QWidget *parent = nullptr);
    // 析构函数
    ~Delete();

signals:
    // 信号backdelete：返回上一界面
    void backdelete();

private:
    // Ui::Delete 指针，指向自动生成的界面UI对象
    Ui::Delete *ui;

private slots:
    // 处理删除按钮点击事件
    void on_DelpushButton_clicked();
    // 处理返回按钮点击事件
    void on_btndelback_clicked();
};

#endif // DELETE_H
