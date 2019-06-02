#include "grade.h"
#include "ui_grade.h"

grade::grade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grade)
{
    ui->setupUi(this);
    setWindowTitle("课程成绩表");
    init();
}

grade::~grade()
{
    delete ui;
}

void grade::init()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from grade order by sno");
    ui->tableView->setModel(model);
}

void grade::find()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString find,sql;
    find=ui->lineEdit->text();
    sql="select * from grade where Sno like '%"+find+"%'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void grade::on_lineEdit_textChanged()
{
    find();
}

void grade::on_btnReflash_clicked()
{
    init();
}


void grade::on_btnChange_clicked()
{
    ChangeGra = new change_grade;
    ChangeGra->show();
}

void grade::on_btnDelete_clicked()
{
    DeleteGra = new delete_grade;
    DeleteGra->show();
}

void grade::on_btnBack_clicked()
{
    this->close();
}
