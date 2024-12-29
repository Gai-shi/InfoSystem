#include "pushin.h"
#include "ui_pushin.h"
#include "salesman.h"
#include "manager.h"
#include "technician.h"

// 构造函数，初始化ui
Pushin::Pushin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pushin)
{
    ui->setupUi(this);
    ui->PManradiobtn->setChecked(true);// 默认选中经理
    ui->POutlineEdit->setPlaceholderText("薪资量化值");
}

// 传递数据容器
void Pushin::getvector(std::vector<QPointer<Company>>&tem){
    pushv=&tem;
}

// 返回主界面
void Pushin::on_btnpushback_clicked(){
    emit this->backpushin();
}

// 确认新增按钮
void Pushin::on_Pushinbtn_clicked(){
    // 获取姓名输入
    QString psin=ui->PInlineEdit->text();
    // 获取金额输入
    QString psout=ui->POutlineEdit->text();

    if(psin==""){
        ui->PInlineEdit->setPlaceholderText("请输入要添加的信息");
        return;
    }
    if(psout==""){
        ui->POutlineEdit->setPlaceholderText("请输入要添加的信息");
        return;
    }

    // 转换输入数据
    bool moneyok;
    std::string nameConvert = psin.toStdString();
    double moneyConvert = psout.toDouble(&moneyok);

    if (!moneyok) {
        ui->POutlineEdit->setPlaceholderText("不是规范的数字");
        return;
    }

    // 根据单选框选项创建对象并加入到容器
    if(ui->PManradiobtn->isChecked()){
        auto *p1=new Manager(nameConvert);
        p1->payUnit=moneyConvert;
        pushv->push_back(p1);
        ui->Plabel->setText("添加成功！");
    }
    else if(ui->PTeradiobtn->isChecked()){
        auto *p1=new Technician(nameConvert);
        p1->payUnit=moneyConvert;
        pushv->push_back(p1);
        ui->Plabel->setText("添加成功！");
    }
    else if(ui->PSaleradiobtn->isChecked()){
        auto *p1=new Salesman(nameConvert);
        p1->payUnit=moneyConvert;
        pushv->push_back(p1);
        ui->Plabel->setText("添加成功！");
    }
    return;
}

// 析构函数
Pushin::~Pushin()
{
    delete ui;
}
