#include "company.h"

// 初始化静态成员变量idFlag，初始值为1000
int Company:: idFlag = 1000;

// 带参数的构造函数，初始化姓名和编号
Company::Company(std::string s):name(s),id(idFlag++){

}
// 默认构造函数
Company::Company(QObject *parent) : QObject(parent) {
    // 构造函数体
}

// toString()方法的实现，用于显示员工的基本信息
QString Company::toString(void){
    return "编号:"+QString::number(this->id)+"; 姓名:"+QString::fromStdString(this->name)+"; 职务:"+classify()+"; 薪资:"+QString::number(getPay());
}
QString Company::toString(char sign){
    return "编号:"+QString::number(this->id)+sign+"姓名:"+QString::fromStdString(this->name)+sign+"职务:"+classify()+sign+"薪资:"+QString::number(getPay());
}

// getPay()方法返回员工的薪资，在子类中重载
double Company::getPay(){
    return 0;
}

// classify()方法返回员工的职务分类，在子类中重载
QString Company::classify(){
    return "";
}
