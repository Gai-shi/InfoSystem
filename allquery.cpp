#include "allquery.h"
#include "Config.h"
#include "ui_allquery.h"

// 构造函数，初始化ui界面
AllQuery::AllQuery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Allquery)
{
    ui->setupUi(this);
}

// 响应"查看所有员工信息"按钮的点击事件，触发返回主查询界面的信号
void AllQuery::on_btnallback_clicked(){
    emit this->backallquery();
}

// 获取员工信息并根据需要保存到文件
void AllQuery::getvector(std::vector<QPointer<Company>>&tem, bool saveInfo){
    // 保存员工信息向量
    allv=tem;
    // 用于存储所有员工信息的字符串
    QString alls="";
    // 遍历员工信息向量
    for(auto &it:allv)
        alls+=(*it).toString()+'\n'; // 格式化为QString并拼接
    // 在文本框中显示员工信息
    ui->AlltextEdit->setPlainText(alls);
    // 保存信息
    if(saveInfo){
        QFile file(savePath);
        // 如果打开文件失败
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            ui->Savelabel->setText("保存失败");
            return;
        }
        // 创建文本流
        QTextStream out(&file);
        // 将所有员工信息写入文件
        out << alls;
        file.close();
        ui->Savelabel->setText("保存到"+QString(savePath));
    }
}
// 析构函数
AllQuery::~AllQuery()
{
    delete ui;
}
