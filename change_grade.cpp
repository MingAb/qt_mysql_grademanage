#include "change_grade.h"
#include "ui_change_grade.h"

change_grade::change_grade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_grade)
{
    ui->setupUi(this);
    setWindowTitle("增改信息");
}

change_grade::~change_grade()
{
    delete ui;
}

void change_grade::on_btnSure_clicked()
{
    QString Sno = ui->lineEdit_Sno->text();
    QString Cno = ui->lineEdit_Cno->text();
    QString Gmark = ui->lineEdit_Gmark->text();

    if(ui->radioButton_Add->isChecked())
    {
        QSqlQueryModel *model0 = new QSqlQueryModel;
        model0->setQuery("select count(*) from grade where Cno='"+Cno+"'AND Sno='"+Sno+"' ");
        QModelIndex index = model0->index(0,0);
        if(index.data()!=0)
        {
            QMessageBox::information(this,"Error","已有此条信息");
        }
        else
        {

            //qDebug() << Cno << Cname << Credit;
            QSqlQueryModel *model1=new QSqlQueryModel;
            model1->setQuery("INSERT INTO grade VALUES ('"+Sno+"','"+Cno+"',"+Gmark+")");
            QMessageBox::information(this,"OK","录入信息成功");
        }

    }
    else
    {
        QSqlQueryModel *model2 = new QSqlQueryModel;
        model2->setQuery("select count(*) from grade where Cno='"+Cno+"' AND Sno='"+Sno+"' ");
        QModelIndex index = model2->index(0,0);
        if(index.data()!=0)
        {
            QSqlQueryModel *model3=new QSqlQueryModel;
            model3->setQuery("UPDATE grade SET Gmark="+Gmark+"\
                 WHERE Cno='"+Cno+"' AND Sno='"+Sno+"'" );
            QMessageBox::information(this,"OK","更改信息成功");
            this->hide();
        }
        else
        {
            QMessageBox::information(this,"Error","没有此条信息");
        }
    }

}

void change_grade::on_btnCancel_clicked()
{
    this->close();
}


