#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <QPushButton>
#include <QThread>
#include "mathtasks.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT // Можем использовать сигналы и слоты

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui; // Доступ к графическому интерфейсу
    QVector<QThread*> threads; // Будем хранить тут все потоки
    QVector<MathTasks*> mathTasks; // Будем хранить тут все математические задачи

public slots:
    void changeValueProgressBar(int value);
    void changeValueProgressBar_2(int value);
    void changeValueProgressBar_3(int value);
    void changeValueProgressBar_4(int value);
    void changeValueProgressBar_5(int value);
    void changeValueProgressBar_6(int value);
    void changeValueProgressBar_7(int value);
    void changeValueProgressBar_8(int value);
    void changeValueProgressBar_9(int value);
    void changeValueProgressBar_10(int value);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_22_clicked();

signals:
    void startOperation(double, double, double, int);
    void startOperation_1(double, double, double, int);
    void startOperation_2(double, double, double, int);
    void startOperation_3(double, double, double, int);
    void startOperation_4(double, double, double, int);
    void startOperation_5(double, double, double, int);
    void startOperation_6(double, double, double, int);
    void startOperation_7(double, double, double, int);
    void startOperation_8(double, double, double, int);
    void startOperation_9(double, double, double, int);
};
#endif // MAINWINDOW_H
