#ifndef RETAKE_H
#define RETAKE_H

#include <QWidget>
#include <QSqlQueryModel>
#include "change_retake.h"
#include "delete_retake.h"

namespace Ui {
class retake;
}

class retake : public QWidget
{
    Q_OBJECT

public:
    explicit retake(QWidget *parent = nullptr);
    ~retake();

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
    Ui::retake *ui;
    change_retake *ChangeRet;
    delete_retake *DeleteRet;
};

#endif // RETAKE_H
