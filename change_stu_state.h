#ifndef CHANGE_STU_STATE_H
#define CHANGE_STU_STATE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class change_stu_state;
}

class change_stu_state : public QWidget
{
    Q_OBJECT

public:
    explicit change_stu_state(QWidget *parent = nullptr);
    ~change_stu_state();

public:
    void SendUserName(QString Data);

public:
    QString username;

private slots:
    void on_btnSure_clicked();

    void on_btnCancel_clicked();

private:
    Ui::change_stu_state *ui;

};

#endif // CHANGE_STU_STATE_H
