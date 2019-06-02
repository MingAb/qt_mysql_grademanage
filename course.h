#ifndef COURSE_H
#define COURSE_H

#include <QWidget>
#include <QSqlQueryModel>
#include "change_course.h"
#include "delete_course.h"

namespace Ui {
class course;
}

class course : public QWidget
{
    Q_OBJECT

public:
    explicit course(QWidget *parent = nullptr);
    ~course();

public:
    void init();

    void find();

private slots:
    void on_btnReflash_clicked();

    void on_btnChange_clicked();

    void on_btnDelete_clicked();

    void on_btnBack_clicked();

    void on_lineEdit_textChanged();

private:
    Ui::course *ui;
    change_course *ChangeCou;
    delete_course *DeleteCou;
};

#endif // COURSE_H
