#include "admin.h"
#include "ui_admin.h"
#include <QSqlQueryModel>

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    setWindowTitle("管理员界面");
}

admin::~admin()
{
    delete ui;
}


void admin::on_pushButton_clicked()
{
    //this->hide();
    stu = new student;
    stu->show();
}

void admin::on_pushButton_2_clicked()
{
    cou = new course;
    cou->show();
}

void admin::on_pushButton_3_clicked()
{
    gra = new grade;
    gra->show();
}

void admin::on_pushButton_4_clicked()
{
    ret = new retake;
    ret->show();
}
