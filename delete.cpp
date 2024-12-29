#include "delete.h"
#include "ui_delete.h"

// 构造函数，初始化ui界面
Delete::Delete(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Delete)
{
    ui->setupUi(this);
    ui->DIDradiobtn->setChecked(true);
}

// 更新员工信息列表，保存传入的员工信息列表
void Delete::getvector(std::vector<QPointer<Company>>&tem){
    delv=&tem;
}

// 触发返回信号，通知界面返回到主界面
void Delete::on_btndelback_clicked(){
    emit this->backdelete();
}

// 根据用户输入删除指定的员工信息（按ID或姓名匹配）
void Delete::on_DelpushButton_clicked(){
    QString dels=ui->DLineEdit->text();
    // 如果输入为空
    if(dels==""){
        ui->DLineEdit->setText("请输入要删除的人员信息");
        return;
    }
    // 按id删除
    if(ui->DIDradiobtn->isChecked()){
        for(auto it=delv->begin();it!=delv->end();it++)
            if(QString::number((*it)->id)==dels){
                delv->erase(it);
                ui->Dellabel_2->setText("删除成功！");
                // QString alls="";
                // for(auto &it:(*delv))
                //     alls+=(*it).toString()+'\n';
                // qDebug()<<alls;
                return;
            }
    }
    // 按姓名删除
    else if(ui->DNameradiobtn->isChecked()){
        for(auto it=delv->begin();it!=delv->end();it++)
            if(QString::fromStdString((*it)->name)==dels){
                delv->erase(it);
                ui->Dellabel_2->setText("删除成功！");
                return;
            }
    }
    // 查无此人
    ui->Dellabel_2->setText("查无此人！");
}

// 析构函数
Delete::~Delete()
{
    delete ui;
}
