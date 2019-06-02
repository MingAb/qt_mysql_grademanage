#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
#include "admin.h"
#include "stu_user.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void sendData(QString );

private slots:
    void on_butExit_clicked();

    void on_btnLoad_clicked();

    void on_checkUser_stateChanged();

    void on_checkAdmin_stateChanged();

private:
    Ui::Widget *ui;
    admin *adm;
    stu_user *suser;
    QString input_user;


};

#endif // WIDGET_H
