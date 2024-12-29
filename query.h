#ifndef QUERY_H
#define QUERY_H

#include <QWidget>
#include <QPointer>
#include "company.h"

using namespace std;

namespace Ui {
    class Query;
}

// Query类：用于查询员工信息
class Query : public QWidget
{
    Q_OBJECT

public:
    // 存储员工对象指针的容器，用于查询
    vector<QPointer<Company>>v;
    // 获取数据容器
    void getvector(vector<QPointer<Company>>&tem);

    // 构造函数
    explicit Query(QWidget *parent = nullptr);
    // Query(vector<QPointer<Company>>&tem);
    // 析构函数
    ~Query();

signals:
    // 返回主界面信号
    void backquery();

private:
    // 自动生成的UI对象
    Ui::Query *ui;

private slots:
    // 查询按钮点击事件
    void on_QpushButton_clicked();
    void on_btnqueryback_clicked();
};

#endif // QUERY_H
