#include "change_course.h"
#include "ui_change_course.h"
#include <QDebug>

change_course::change_course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_course)
{
    ui->setupUi(this);
    setWindowTitle("增改信息");
}

change_course::~change_course()
{
    delete ui;
}

void change_course::on_btnSure_clicked()
{
    QString Cno = ui->lineEdit_Cno->text();
    QString Cname = ui->lineEdit_Cname->text();
    QString Credit = ui->lineEdit_Credit->text();

    if(ui->radioButton_Add->isChecked())
    {
        QSqlQueryModel *model0 = new QSqlQueryModel;
        model0->setQuery("select count(*) from course where Cno='"+Cno+"' ");
        QModelIndex index = model0->index(0,0);
        if(index.data()!=0)
        {
            QMessageBox::information(this,"Error","已有此课程信息");
        }
        else
        {
            //qDebug() << Cno << Cname << Credit;
            QSqlQueryModel *model1=new QSqlQueryModel;
            model1->setQuery("INSERT INTO course VALUES ('"+Cno+"','"+Cname+"',"+Credit+")");
            QMessageBox::information(this,"OK","录入信息成功");

        }
    }
    else
    {
        QSqlQueryModel *model2 = new QSqlQueryModel;
        model2->setQuery("select count(*) from student where Cno='"+Cno+"' ");
        QModelIndex index = model2->index(0,0);
        if(index.data()!=0)
        {
            QSqlQueryModel *model3=new QSqlQueryModel;
            model3->setQuery("UPDATE course SET Cname='"+Cname+"',\
                Credit="+Credit+" WHERE Cno='"+Cno+"'");
            QMessageBox::information(this,"OK","更改信息成功");
            this->hide();
        }
        else
        {
            QMessageBox::information(this,"Error","没有此课程信息");
        }
    }

}

void change_course::on_btnCancel_clicked()
{
    this->close();
}
