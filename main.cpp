#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include<QSqlDatabase>

bool opendatabase();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    Widget w;
    opendatabase();
    w.setWindowTitle("登录系统");
    w.show();

    return a.exec();
}

bool opendatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("grademanager");
    db.setUserName("root");
    db.setPassword("1234");

    if(!db.open())
    {
        QMessageBox::warning(NULL, "警告", "无法连接到数据库");
        return false;
    }
    else{
        qDebug() << "连接数据库成功";
        return true;
    }
}
