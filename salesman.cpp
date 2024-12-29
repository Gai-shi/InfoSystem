#include "salesman.h"

// 构造函数：调用父类Company的构造函数来初始化销售人员薪资
Salesman::Salesman(std::string a):Company(a){
    payUnit=125000;
}

// 修改或设置当月销售额
void Salesman::setSales(double a){
    payUnit=a;
};
