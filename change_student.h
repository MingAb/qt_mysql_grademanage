#ifndef CHANGE_STUDENT_H
#define CHANGE_STUDENT_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class change_student;
}

class change_student : public QWidget
{
    Q_OBJECT

public:
    explicit change_student(QWidget *parent = nullptr);
    ~change_student();

private slots:
    void on_btnCancel_clicked();

    void on_btnSure_clicked();

private:
    Ui::change_student *ui;
};

#endif // CHANGE_STUDENT_H
