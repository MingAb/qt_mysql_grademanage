#ifndef STU_USER_H
#define STU_USER_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QDebug>
#include "change_stu_state.h"
#include "change_stu_password.h"

namespace Ui {
class stu_user;
}

class stu_user : public QWidget
{
    Q_OBJECT

public:
    explicit stu_user(QWidget *parent = nullptr);
    ~stu_user();

public:
    void init();
    void t_inputusername(QString Data);

public:
    QString username;
    QString stu_title;
private slots:
    void on_btnPerinfo_clicked();

    void on_btnBack_clicked();

    void on_btnClass_clicked();

    void on_btnGrade_clicked();

    void on_btn_clicked();

    void on_pushButton_clicked();

    void on_btnChangePswd_clicked();

private:
    Ui::stu_user *ui;
    change_stu_state *state_change;
    change_stu_password *pswd_change;


};

#endif // STU_USER_H
