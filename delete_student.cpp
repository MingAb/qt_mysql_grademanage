#include "delete_student.h"
#include "ui_delete_student.h"
#include <QDebug>
delete_student::delete_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_student)
{
    ui->setupUi(this);
    setWindowTitle("删除信息");
}

delete_student::~delete_student()
{
    delete ui;
}

void delete_student::on_btnDelet_clicked()
{
    QString number = ui->lineEdit->text();
    //qDebug() << number;

    QSqlQueryModel *model0 = new QSqlQueryModel;
    model0->setQuery("select count(*) from student where sno='"+number+"' ");
    QModelIndex index = model0->index(0,0);
    if(index.data()!=0)
    {
        QString sql = QString("delete from student where Sno = '%1'").arg(number);

        //开启事务
        QSqlDatabase::database().transaction();
        QSqlQuery query1;
        query1.exec(sql);

        ui->btnDelet->setEnabled(false);

    }
    else
    {
        QMessageBox::information(this,"Error","没有此学生信息");
    }
}

void delete_student::on_btnSure_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();
    QMessageBox::information(this,"OK","删除成功");
}

void delete_student::on_btnCancel_clicked()
{
    //回滚
    QSqlDatabase::database().rollback();
    this->close();
}
