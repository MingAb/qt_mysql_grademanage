#include "course.h"
#include "ui_course.h"

course::course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::course)
{
    ui->setupUi(this);
    setWindowTitle("开课计划表");
    init();
}

course::~course()
{
    delete ui;
}

void course::init()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from course order by Cno");
    ui->tableView->setModel(model);
}

void course::on_btnReflash_clicked()
{
    init();
}

void course::on_btnChange_clicked()
{
    ChangeCou = new change_course;
    ChangeCou->show();
}

void course::on_btnDelete_clicked()
{
    DeleteCou = new delete_course;
    DeleteCou->show();
}

void course::find()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString find,sql;
    find=ui->lineEdit->text();
    sql="select * from course where Cno like '%"+find+"%'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}
void course::on_btnBack_clicked()
{
    this->close();
}

void course::on_lineEdit_textChanged()
{
    find();
}
