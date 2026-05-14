#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // проверка драйверов
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    if (!QSqlDatabase::isDriverAvailable("QPSQL")) {

        QMessageBox::critical(
            nullptr,
            "Ошибка",
            "Драйвер QPSQL НЕ найден"
            );

        return -1;
    }

    MainWindow w;
    w.show();

    return a.exec();
}