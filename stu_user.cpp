#include "stu_user.h"
#include "ui_stu_user.h"

stu_user::stu_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stu_user)
{
    ui->setupUi(this);
}

stu_user::~stu_user()
{
    delete ui;
}

void stu_user::t_inputusername(QString Data)
{
    username=Data;
    QSqlQueryModel *model1 = new QSqlQueryModel;
    model1->setQuery("select * from student where Sno='"+Data+"'");
    ui->tableView->setModel(model1);

    QSqlQueryModel *model2 = new QSqlQueryModel;
    model2->setQuery("select Sname from student where Sno='"+Data+"'");
    QModelIndex index1 = model2->index(0,0);
    QString sname=index1.data().toString();

    stu_title = QString("欢迎你：%1").arg(sname);
    setWindowTitle(stu_title);

    //qDebug() << username;
}

void stu_user::init()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from student where Sno='"+username+"'");
    ui->tableView->setModel(model);
}

void stu_user::on_btnPerinfo_clicked()
{
    init();
}

void stu_user::on_btnClass_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select * from course");
    ui->tableView->setModel(model);
}

void stu_user::on_btnGrade_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select grade.Sno,course.Cname,grade.Gmark,course.Credit from grade \
        left join course on grade.cno=course.cno where grade.Sno='"+username+"'");
    ui->tableView->setModel(model);
}

void stu_user::on_btn_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select course.Cno,course.Cname,course.Credit,grade.Gmark,retake.retake from retake \
        left join course on retake.cno=course.cno\
        left join grade on retake.sno=grade.sno and retake.cno=grade.cno\
        where retake.Sno='"+username+"'");
    ui->tableView->setModel(model);
}

void stu_user::on_pushButton_clicked()
{
    state_change = new change_stu_state;
    state_change->SendUserName(username);
    state_change->show();
}

void stu_user::on_btnChangePswd_clicked()
{
    pswd_change = new change_stu_password;
    pswd_change->SendUserName(username);
    pswd_change->show();
}


void stu_user::on_btnBack_clicked()
{
    this->close();
}

