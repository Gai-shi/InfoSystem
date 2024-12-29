#include "technician.h"

// 构造函数：调用父类Company的构造函数来初始化销售人员薪资
Technician::Technician(std::string a):Company(a){
    payUnit=60;
}

// 修改或设置当月工作时间
void Technician::setWorkTime(double a){
    payUnit=a;
};
