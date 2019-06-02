#include "change_stu_password.h"
#include "ui_change_stu_password.h"
#include <QDebug>

change_stu_password::change_stu_password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_stu_password)
{
    ui->setupUi(this);
    setWindowTitle("密码修改");
}

change_stu_password::~change_stu_password()
{
    delete ui;
}

void change_stu_password::SendUserName(QString Data)
{
    username=Data;
}

void change_stu_password::on_btnSure_clicked()
{
    QString Old_Pswd = ui->lineEdit_oldpswd->text();
    QString New_Pswd = ui->lineEdit_newpswd->text();
    QString Confirm_Pswd = ui->lineEdit_confirm->text();

    QSqlQueryModel* model0 = new QSqlQueryModel;
    model0->setQuery("select password from allpassword where user='"+username+"' ");
    QModelIndex index = model0->index(0,0);

    if(index.data()!=Old_Pswd)
    {
        QMessageBox::information(this,"Error","原密码错误");
    }
    else
    {
         if(New_Pswd!=Confirm_Pswd)
         {
             QMessageBox::information(this,"Error","两次输入密码不一致");
         }
         else
         {
             qDebug() << New_Pswd << username;
             QSqlQueryModel *model1=new QSqlQueryModel;
             model1->setQuery("UPDATE allpassword SET password='"+New_Pswd+"'\
                 WHERE user='"+username+"'" );
             QMessageBox::information(this,"OK","更改密码成功");
             this->hide();
         }
    }
}

void change_stu_password::on_btnCancel_clicked()
{
    this->close();
}
