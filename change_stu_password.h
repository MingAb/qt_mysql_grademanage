#ifndef CHANGE_STU_PASSWORD_H
#define CHANGE_STU_PASSWORD_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class change_stu_password;
}

class change_stu_password : public QWidget
{
    Q_OBJECT

public:
    explicit change_stu_password(QWidget *parent = nullptr);
    ~change_stu_password();

public:
    void SendUserName(QString Data);

public:
    QString username;

private slots:
    void on_btnSure_clicked();

    void on_btnCancel_clicked();

private:
    Ui::change_stu_password *ui;
};

#endif // CHANGE_STU_PASSWORD_H
