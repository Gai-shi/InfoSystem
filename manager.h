#ifndef MANAGER_H
#define MANAGER_H

#include "company.h"

// Manager类: 经理
class Manager : public Company
{
public:
    // 构造函数，继承自父类
    explicit Manager(std::string a);

private:
    // 重载父类方法，经理拿固定月薪8000元
    double getPay() override{
        return payUnit;
    }
    // 重载父类方法
    QString classify() override{
        return "经理";
    }
};

#endif // MANAGER_H
