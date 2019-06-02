#include "delete_retake.h"
#include "ui_delete_retake.h"

delete_retake::delete_retake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_retake)
{
    ui->setupUi(this);
    setWindowTitle("删除信息");
}

delete_retake::~delete_retake()
{
    delete ui;
}

void delete_retake::on_btnCancel_clicked()
{
    this->close();
}

void delete_retake::on_btnDelete_clicked()
{
    QString Sno = ui->lineEdit_Sno->text();
    QString Cno = ui->lineEdit_Cno->text();

    QSqlQueryModel *model1 = new QSqlQueryModel;
    model1->setQuery("select count(*) from retake where \
        Cno='"+Cno+"' AND Sno='"+Sno+"' ");
    QModelIndex index = model1->index(0,0);
    if(index.data()!=0)
    {
        QSqlQueryModel *model2=new QSqlQueryModel;
        model2->setQuery("delete from retake where \
             Cno='"+Cno+"' AND Sno='"+Sno+"' ");
        QMessageBox::information(this,"OK","删除信息成功");
        this->hide();
    }
    else
    {
        QMessageBox::information(this,"Error","没有此条信息");
    }
}

