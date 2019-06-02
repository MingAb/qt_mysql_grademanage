#ifndef DELETE_GRADE_H
#define DELETE_GRADE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class delete_grade;
}

class delete_grade : public QWidget
{
    Q_OBJECT

public:
    explicit delete_grade(QWidget *parent = nullptr);
    ~delete_grade();

private slots:
    void on_btnDelete_clicked();

    void on_btnCancel_clicked();

private:
    Ui::delete_grade *ui;
};

#endif // DELETE_GRADE_H
