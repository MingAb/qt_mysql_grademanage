#include "change_student.h"
#include "ui_change_student.h"
#include <QDebug>
change_student::change_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
    setWindowTitle("增改信息");
}

change_student::~change_student()
{
    delete ui;
}

void change_student::on_btnCancel_clicked()
{
    this->hide();
}

void change_student::on_btnSure_clicked()
{
    QString number = ui->textNo->text();
    QString name = ui->textName->text();
    QString age = ui->textAge->text();
    QString sclass = ui->textClass->text();
    QString sex = ui->textSex->text();

    if(ui->radioButton_Add->isChecked())
    {
        QSqlQueryModel *model0 = new QSqlQueryModel;
        model0->setQuery("select count(*) from student where sno='"+number+"' ");
        QModelIndex index = model0->index(0,0);
        if(index.data()!=0)
        {
            QMessageBox::information(this,"Error","已有此学生信息");
        }
        else
        {
            qDebug() << number << name << sex << age <<sclass;
            QSqlQueryModel *model1=new QSqlQueryModel;
            model1->setQuery("INSERT INTO student VALUES ('"+number+"','"+name+"','"+sex+"',"+age+",'"+sclass+"')");
            QMessageBox::information(this,"OK","录入信息成功");

        }
    }
    else
    {
        QSqlQueryModel *model2 = new QSqlQueryModel;
        model2->setQuery("select count(*) from student where sno='"+number+"' ");
        QModelIndex index = model2->index(0,0);
        if(index.data()!=0)
        {
            QSqlQueryModel *model3=new QSqlQueryModel;
            model3->setQuery("UPDATE student SET Sname='"+name+"',Ssex='"+sex+"',\
                Sage="+age+",Clno='"+sclass+"' WHERE Sno='"+number+"'");
            QMessageBox::information(this,"OK","更改信息成功");
            this->hide();
        }
        else
        {
            QMessageBox::information(this,"Error","没有此学生信息");
        }
    }

}
