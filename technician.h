#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "company.h"

// Technician类：技术人员
class Technician : public Company
{
public:
    // 构造函数，继承自父类
    explicit Technician(std::string a);

private:
    // 修改或设置当月工作时间
    void setWorkTime(double a);

    // 重载父类方法，技术人员按每小时100元领取月薪
    double getPay() override{
        return payUnit*100;
    }

    // 重载父类方法
    QString classify() override{
        return "技术人员";
    }
};

#endif // TECHNICIAN_H
