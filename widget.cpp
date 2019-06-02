#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_butExit_clicked()
{
    qApp->exit();
}

void Widget::on_btnLoad_clicked()
{
    input_user=ui->textUsername->text();
    QString input_passwd=ui->textPassword->text();

    if(ui->checkAdmin->isChecked())
    {
        if(input_user =="admin" && input_passwd =="admin")
        {
            this->hide();
            adm = new admin;
            adm->show();
        }
        else
        {
            QMessageBox::information(this,"Error","用户名或密码错误");
        }
    }
    else
    {
        QSqlQueryModel* model1 = new QSqlQueryModel;
        model1->setQuery("select count(*) from allpassword where user='"+input_user+"' ");
        QModelIndex index1 = model1->index(0,0);

        QSqlQueryModel* model2 = new QSqlQueryModel;
        model2->setQuery("select password from allpassword where user='"+input_user+"' ");
        QModelIndex index2 = model2->index(0,0);

        if(index1.data()!=0 && index2.data()== input_passwd)
        {
            this->hide();
            suser = new stu_user();
            suser->t_inputusername(input_user);
            suser->show();
        }
        else
        {
            QMessageBox::information(this,"Error","用户名或密码错误");
        }
    }
}

void Widget::on_checkUser_stateChanged()
{
    if(ui->checkUser->isChecked())
        ui->checkAdmin->setCheckState(Qt::Unchecked);
    else
        ui->checkAdmin->setCheckState(Qt::Checked);
}

void Widget::on_checkAdmin_stateChanged()
{
    if(ui->checkAdmin->isChecked())
        ui->checkUser->setCheckState(Qt::Unchecked);
    else
        ui->checkUser->setCheckState(Qt::Checked);

}
