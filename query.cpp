#include "query.h"
#include "ui_query.h"

// 构造函数
Query::Query(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Query)
{
    ui->setupUi(this);
    ui->IDradioButton->setChecked(true); // 默认选择ID查询
    // getvector();
}

// 获取员工数据容器
void Query::getvector(vector<QPointer<Company>>&tem){
    v=tem;
}

// 返回按钮槽函数
void Query::on_btnqueryback_clicked(){
    emit this->backquery();
}

// 查询按钮点击事件
void Query::on_QpushButton_clicked(){
    QString s=ui->InlineEdit->text();
    if(s==""){
        ui->InlineEdit->setText("请输入要查询的信息");
        return;
    }
    // 根据选择的查询条件（ID或姓名）进行员工信息查询
    if(ui->IDradioButton->isChecked()){
        for(auto &it:v)
            if(QString::number((*it).id)==s){
                QString text=(*it).toString('\n');
                ui->Outlabel->setText(text);
                return;
            }
    }
    else if(ui->NameradioButton->isChecked()){
        for(auto &it:v)
            if(QString::fromStdString((*it).name)==s){
                QString text=(*it).toString('\n');
                ui->Outlabel->setText(text);
                return;
            }
    }
    ui->Outlabel->setText("查无此人");
}

// 析构函数
Query::~Query()
{
    delete ui;
}
