#include "modify.h"
#include "ui_modify.h"

// 构造函数，初始化ui界面
Modify::Modify(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Modify)
{
    ui->setupUi(this);
    // 默认选中按ID修改
    ui->MIDradiobtn->setChecked(true);
}

// 返回主界面
void Modify::on_btnmodback_clicked(){
    emit this->backmodify();
}

// 接收员工数据
void Modify::getvector(std::vector<QPointer<Company>>&tem){
    modv=tem;
}

// 提示输入框的提示信息
void Modify::on_MSalarybtn_clicked(){
    if(ui->MRowLE->text().isEmpty())
        ui->MRowLE->setPlaceholderText("人员编号");
    else
        ui->MRowLE->setText("人员编号");
    if(ui->MAfterLE->text().isEmpty())
        ui->MAfterLE->setPlaceholderText("薪资量化值");
    else
        ui->MAfterLE->setText("薪资量化值");
}

// 确认修改信息
void Modify::on_MEnsurebtn_clicked(){
    QString sin=ui->MRowLE->text();
    QString sout=ui->MAfterLE->text();
    if(sin==""){
        ui->MRowLE->setPlaceholderText("需要修改的信息");
        return;
    }
    if(sout==""){
        ui->MAfterLE->setPlaceholderText("需要修改的信息");
        return;
    }
    if(ui->MIDradiobtn->isChecked()){
        // 按编号修改
        for(auto &it:modv)
            if(QString::number((*it).id)==sin){
                bool ok;
                int num = sout.toInt(&ok);
                if (ok) {
                    (*it).id=num;
                    ui->label_3->setText("修改成功！");
                } else {
                    ui->MAfterLE->setText("输入错误，不是整数");
                }
                return;
            }
        ui->label_3->setText("查无此人");
        return;
    }
    else if(ui->MNameradiobtn->isChecked()){
        // 按姓名修改
        for(auto &it:modv)
            if(QString::fromStdString((*it).name)==sin){
                (*it).name=sout.toStdString();
                ui->label_3->setText("修改成功！");
                return;
            }
        ui->label_3->setText("查无此人");
        return;
    }
    else if(ui->MSalarybtn->isChecked()){
        // 修改薪资或相关信息
        for(auto &it:modv)
            if(QString::number((*it).id)==sin){
                bool ok;
                double numdouble = sout.toDouble(&ok);
                if (ok) {
                    (*it).payUnit=numdouble;
                    ui->label_3->setText("修改成功！");
                } else {
                    ui->MAfterLE->setText("输入错误，不是数值！");
                }
                return;
            }
        ui->label_3->setText("查无此人");
        return;
    }
};

// 析构函数
Modify::~Modify()
{
    delete ui;
}
