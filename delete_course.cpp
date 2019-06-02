#include "delete_course.h"
#include "ui_delete_course.h"

delete_course::delete_course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_course)
{
    ui->setupUi(this);
    setWindowTitle("删除信息");
}

delete_course::~delete_course()
{
    delete ui;
}



void delete_course::on_btnDelete_clicked()
{
    QString Cno = ui->lineEdit_Cno->text();
    //qDebug() << number;

    QSqlQueryModel *model0 = new QSqlQueryModel;
    model0->setQuery("select count(*) from course where Cno='"+Cno+"' ");
    QModelIndex index = model0->index(0,0);
    if(index.data()!=0)
    {
        QString sql = QString("delete from course where Cno = '%1'").arg(Cno);

        QSqlQueryModel *model0 = new QSqlQueryModel;
        model0->setQuery(sql);

         QMessageBox::information(this,"OK","删除课程信息成功");

    }
    else
    {
        QMessageBox::information(this,"Error","没有此课程信息");
    }
}

void delete_course::on_btnCancel_clicked()
{
    this->close();
}
