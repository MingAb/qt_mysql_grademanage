#ifndef CHANGE_GRADE_H
#define CHANGE_GRADE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class change_grade;
}

class change_grade : public QWidget
{
    Q_OBJECT

public:
    explicit change_grade(QWidget *parent = nullptr);
    ~change_grade();

private slots:
    void on_btnCancel_clicked();

    void on_btnSure_clicked();

private:
    Ui::change_grade *ui;
};

#endif // CHANGE_GRADE_H
