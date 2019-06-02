#ifndef GRADE_H
#define GRADE_H

#include <QWidget>
#include <QSqlQueryModel>
#include "change_grade.h"
#include "delete_grade.h"

namespace Ui {
class grade;
}

class grade : public QWidget
{
    Q_OBJECT

public:
    explicit grade(QWidget *parent = nullptr);
    ~grade();

public:
    void init();

    void find();

private slots:
    void on_btnReflash_clicked();

    void on_lineEdit_textChanged();

    void on_btnChange_clicked();

    void on_btnDelete_clicked();

    void on_btnBack_clicked();

private:
    Ui::grade *ui;
    change_grade *ChangeGra;
    delete_grade *DeleteGra;
};

#endif // GRADE_H
