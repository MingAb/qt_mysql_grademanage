#include "student.h"
#include "ui_student.h"

student::student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
    setWindowTitle("学生信息表");
    init();
}

student::~student()
{
    delete ui;
}

void student::init()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from student order by sno");
    ui->tableView->setModel(model);
}


void student::find()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString find,sql;
    find=ui->textFindnum->text();
    sql="select * from student where Sno like '%"+find+"%'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void student::on_textFindnum_textChanged()
{
    find();
}

void student::on_btnRef_clicked()
{
    init();
}

void student::on_btnChange_clicked()
{
    ChangeStu = new change_student;
    ChangeStu->show();
}

void student::on_btnDel_clicked()
{
    DeleteStu = new delete_student;
    DeleteStu->show();
}

void student::on_btnSort_clicked()
{
    QString sql0;
    QSqlQueryModel *model = new QSqlQueryModel;
    if(ui->checkDesc->isChecked())
    {
        if(ui->comboBox->currentText()=="学号")
        {
            sql0="select * from student order by Sno desc";
        }
        else if (ui->comboBox->currentText()=="姓名")
        {
            sql0="select * from student order by Sname desc";
        }
        else if (ui->comboBox->currentText()=="班级")
        {
            sql0="select * from student order by Clno desc";
        }
        else if (ui->comboBox->currentText()=="性别")
        {
            sql0="select * from student order by Ssex desc";
        }
        else if (ui->comboBox->currentText()=="年龄")
        {
            sql0="select * from student order by Sage desc";
        }
    }
    else
    {
        if(ui->comboBox->currentText()=="学号")
        {
            sql0="select * from student order by Sno";
        }
        else if (ui->comboBox->currentText()=="姓名")
        {
            sql0="select * from student order by Sname";
        }
        else if (ui->comboBox->currentText()=="班级")
        {
            sql0="select * from student order by Clno";
        }
        else if (ui->comboBox->currentText()=="性别")
        {
            sql0="select * from student order by Ssex";
        }
        else if (ui->comboBox->currentText()=="年龄")
        {
            sql0="select * from student order by Sage";
        }
    }
    model->setQuery(sql0);
    ui->tableView->setModel(model);
}

void student::on_btnBack_clicked()
{
    this->close();
}
