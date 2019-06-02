#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "student.h"
#include "course.h"
#include "grade.h"
#include "retake.h"

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::admin *ui;
    student *stu;
    course *cou;
    grade *gra;
    retake *ret;
};

#endif // ADMIN_H
