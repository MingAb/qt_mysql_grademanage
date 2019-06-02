#ifndef CHANGE_COURSE_H
#define CHANGE_COURSE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class change_course;
}

class change_course : public QWidget
{
    Q_OBJECT

public:
    explicit change_course(QWidget *parent = nullptr);
    ~change_course();

private slots:
    void on_btnSure_clicked();

    void on_btnCancel_clicked();

private:
    Ui::change_course *ui;
};

#endif // CHANGE_COURSE_H
