#ifndef SALESMAN_H
#define SALESMAN_H

#include "company.h"

// Salesman类：推销员
class Salesman : public Company
{
public:
    // 构造函数，继承自父类
    explicit Salesman(std::string a);

private:
    // 修改或设置当月销售额
    void setSales(double a);
    // // double money=125000;

    // 重载父类方法，推销人员的月薪按当月的销售额的4%提成
    double getPay() override{
        return payUnit*0.04;
    }

    // 重载父类方法
    QString classify() override{
        return "销售人员";
    }
};

#endif // SALESMAN_H
