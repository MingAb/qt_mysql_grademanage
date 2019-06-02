#ifndef CHANGE_RETAKE_H
#define CHANGE_RETAKE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class change_retake;
}

class change_retake : public QWidget
{
    Q_OBJECT

public:
    explicit change_retake(QWidget *parent = nullptr);
    ~change_retake();

private slots:
    void on_btnSure_clicked();

    void on_btnCancel_clicked();

private:
    Ui::change_retake *ui;
};

#endif // CHANGE_RETAKE_H
