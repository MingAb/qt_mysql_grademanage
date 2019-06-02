#ifndef DELETE_COURSE_H
#define DELETE_COURSE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class delete_course;
}

class delete_course : public QWidget
{
    Q_OBJECT

public:
    explicit delete_course(QWidget *parent = nullptr);
    ~delete_course();


private slots:
    void on_btnDelete_clicked();

    void on_btnCancel_clicked();

private:
    Ui::delete_course *ui;
};

#endif // DELETE_COURSE_H
