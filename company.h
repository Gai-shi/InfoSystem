#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>
#include <string>

// 基类Company
class Company: public QObject
{
    Q_OBJECT
public:
    // 构造函数：接受员工姓名作为参数进行初始化，编号自动分配
    explicit Company(std::string s);
    // 默认构造函数：父类QObject的构造函数
    explicit Company(QObject *parent = nullptr);
    // 员工姓名
    std::string name;
    // 员工编号
    int id;
    // 员工薪资计算单位
    double payUnit;
    // 显示员工的个人信息，格式化为QString类型
    QString toString(void);
    QString toString(char);

private:
    // 静态全局属性idFlag，记录当前员工编号的索引值，用于生成唯一的员工编号
    static int idFlag;
    // 获取当月薪水，虚拟函数，可被派生类重载
    virtual double getPay();
    // 获取员工的分类信息，虚拟函数，可被派生类重载
    virtual QString classify();

signals:
    // 定义信号queryInfo，用于查询员工信息
    void queryInfo(void);
};

#endif // COMPANY_H
