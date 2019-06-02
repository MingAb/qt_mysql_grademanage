#include "change_stu_state.h"
#include "ui_change_stu_state.h"

change_stu_state::change_stu_state(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::change_stu_state)
{
    ui->setupUi(this);
    setWindowTitle("重修选择");
}

change_stu_state::~change_stu_state()
{
    delete ui;
}

void change_stu_state::SendUserName(QString Data)
{
    username=Data;
}

void change_stu_state::on_btnSure_clicked()
{
    QString Cno=ui->lineEdit->text();

    QSqlQueryModel *model0 = new QSqlQueryModel;
    model0->setQuery("select count(*) from retake where Cno='"+Cno+"'AND Sno='"+username+"' ");
    QModelIndex index = model0->index(0,0);
    if(index.data()!=0)
    {
        if(ui->checkBox_Retkae->isChecked())
        {
            QSqlQueryModel *model1=new QSqlQueryModel;
            model1->setQuery("UPDATE retake SET retake='是'\
                WHERE Cno='"+Cno+"' AND Sno='"+username+"'" );
            QMessageBox::information(this,"OK","更改状态成功");
            this->hide();
        }
        else
        {
            QSqlQueryModel *model2=new QSqlQueryModel;
            model2->setQuery("UPDATE retake SET retake='否'\
                WHERE Cno='"+Cno+"' AND Sno='"+username+"'" );
            QMessageBox::information(this,"OK","更改状态成功");
            this->hide();
        }
    }
    else
    {
        QMessageBox::information(this,"Error","这门不用重修");
    }

}

void change_stu_state::on_btnCancel_clicked()
{
    this->close();
}
