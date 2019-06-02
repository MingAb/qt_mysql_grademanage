#ifndef DELETE_STUDENT_H
#define DELETE_STUDENT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class delete_student;
}

class delete_student : public QWidget
{
    Q_OBJECT

public:
    explicit delete_student(QWidget *parent = nullptr);
    ~delete_student();

private slots:
    void on_btnDelet_clicked();

    void on_btnSure_clicked();

    void on_btnCancel_clicked();

private:
    Ui::delete_student *ui;
};

#endif // DELETE_STUDENT_H
