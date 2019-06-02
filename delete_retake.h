#ifndef DELETE_RETAKE_H
#define DELETE_RETAKE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class delete_retake;
}

class delete_retake : public QWidget
{
    Q_OBJECT

public:
    explicit delete_retake(QWidget *parent = nullptr);
    ~delete_retake();

private slots:
    void on_btnCancel_clicked();

    void on_btnDelete_clicked();

private:
    Ui::delete_retake *ui;
};

#endif // DELETE_RETAKE_H
