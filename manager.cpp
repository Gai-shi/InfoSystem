#include "manager.h"

// 构造函数：调用父类Company的构造函数来初始化经理薪资
Manager::Manager(std::string a):Company(a){
    payUnit=8000;
}
