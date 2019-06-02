#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <QSqlQueryModel>
#include "change_student.h"
#include "delete_student.h"

namespace Ui {
class student;
}

class student : public QWidget
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    ~student();

public:
    void init();

    void find();

private slots:
    void on_btnBack_clicked();

    void on_btnRef_clicked();

    void on_btnChange_clicked();

    void on_btnDel_clicked();

    void on_btnSort_clicked();

    void on_textFindnum_textChanged();

private:
    Ui::student *ui;
    change_student *ChangeStu;
    delete_student *DeleteStu;
};

#endif // STUDENT_H
