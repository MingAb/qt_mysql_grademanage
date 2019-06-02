#include "retake.h"
#include "ui_retake.h"

retake::retake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::retake)
{
    ui->setupUi(this);
    setWindowTitle("重读重修表");
    init();
}

retake::~retake()
{
    delete ui;
}

void retake::init()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from retake order by sno");
    ui->tableView->setModel(model);
}

void retake::find()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString find,sql;
    find=ui->lineEdit->text();
    sql="select * from retake where Sno like '%"+find+"%'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void retake::on_lineEdit_textChanged()
{
    find();
}

void retake::on_btnReflash_clicked()
{
    init();
}

void retake::on_btnChange_clicked()
{
    ChangeRet = new change_retake;
    ChangeRet->show();
}

void retake::on_btnDelete_clicked()
{
    DeleteRet = new delete_retake;
    DeleteRet->show();
}

void retake::on_btnBack_clicked()
{
    this->close();
}

