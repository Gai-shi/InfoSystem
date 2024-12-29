#include "infosys.h"
#include "ui_infosys.h"
#include "salesman.h"
#include "technician.h"
#include "manager.h"

// 构造函数，初始化ui界面
InfoSys::InfoSys(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InfoSys)
{
    ui->setupUi(this);

    // 创建一些默认的员工对象，并添加到员工容器中
    auto *p1=new Salesman("花花");
    auto *p2=new Technician("欣欣");
    auto *p3=new Manager("Youthi");
    employee.push_back(p1);
    employee.push_back(p2);
    employee.push_back(p3);
    // for(auto &it:employee)
    //     (*it).toString();
}

// 查询员工信息，创建查询窗口
void InfoSys::on_p1button_clicked(){
    qDebug()<<__LINE__;
    query=new Query();
    query->getvector(employee);
    // 隐藏主界面
    this->hide();
    // 显示查询窗口
    query->show();
    // 连接信号和槽函数
    connect(query,&Query::backquery,this,[=](){
        query->hide();
        this->show();
    });
}

// 创建查看所有信息窗口，并显示员工列表
void InfoSys::on_p2button_clicked(){
    allQuery=new AllQuery();
    allQuery->getvector(employee);
    this->hide();
    allQuery->show();
    connect(allQuery,&AllQuery::backallquery,this,[&](){
        allQuery->hide();
        this->show();
    });
}

// 修改员工信息，创建修改信息窗口
void InfoSys::on_p3button_clicked(){
    modify=new Modify();
    modify->getvector(employee);
    this->hide();
    modify->show();
    connect(modify,&Modify::backmodify,this,[=](){
        modify->hide();
        this->show();
    });
}

// 删除员工信息，创建删除信息窗口
void InfoSys::on_p4button_clicked(){
    del=new Delete();
    del->getvector(employee);
    this->hide();
    del->show();
    connect(del,&Delete::backdelete,this,[=](){
        del->hide();
        this->show();
    });
}

// 增加员工，创建新增信息窗口
void InfoSys::on_p5button_clicked(){
    pushin=new Pushin();
    pushin->getvector(employee);
    this->hide();
    pushin->show();
    connect(pushin,&Pushin::backpushin,this,[=](){
        pushin->hide();
        this->show();
    });
    // QString alls="";
    // for(auto &it:employee)
    //     alls+=(*it).toString()+'\n';
    // qDebug()<<alls;
}

// 保存所有员工信息到文件
void InfoSys::on_p6button_clicked(){
    allQuery=new AllQuery();
    allQuery->getvector(employee,true);
    this->hide();
    allQuery->show();
    connect(allQuery,&AllQuery::backallquery,this,[=](){
        allQuery->hide();
        this->show();
    });
}

// 析构函数
InfoSys::~InfoSys()
{
    delete ui;
}
