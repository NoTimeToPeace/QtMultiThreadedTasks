#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем окно по центру экрана
    this->setGeometry(QApplication::desktop()->screenGeometry(0).width()/2-400, QApplication::desktop()->screenGeometry(0).height()/2-175, 800, 350); // Устанавливаем окно в центр экрана

    // Создаём 10 потоков и 10 задач
    for (int i = 0; i < 10; i++) {
        threads.push_back(new QThread(this));
        mathTasks.push_back(new MathTasks());
    }

    // Сигналы для слотов математических операций
    connect(this, &MainWindow::startOperation  , mathTasks[0], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_1, mathTasks[1], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_2, mathTasks[2], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_3, mathTasks[3], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_4, mathTasks[4], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_5, mathTasks[5], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_6, mathTasks[6], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_7, mathTasks[7], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_8, mathTasks[8], &MathTasks::Task);
    connect(this, &MainWindow::startOperation_9, mathTasks[9], &MathTasks::Task);

    // Сигналы для изменения шкалы выполнения
    connect(mathTasks[0], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar);
    connect(mathTasks[1], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_2);
    connect(mathTasks[2], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_3);
    connect(mathTasks[3], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_4);
    connect(mathTasks[4], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_5);
    connect(mathTasks[5], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_6);
    connect(mathTasks[6], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_7);
    connect(mathTasks[7], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_8);
    connect(mathTasks[8], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_9);
    connect(mathTasks[9], &MathTasks::ChangeProgressBar, this, &MainWindow::changeValueProgressBar_10);

    qDebug() << "GUI thread" << this->thread(); // поток, в котором идёт отрисовка виджетов
}

MainWindow::~MainWindow()
{
    qDebug() << "Destructor MainWindow";
    // Удаляем все объекты математических задач и потоки
    for (int i = 0; i < 10; i++) {
        delete mathTasks[i];
        delete threads[i];
    }
}

// Шкала выполнения задачи из первого потока
void MainWindow::changeValueProgressBar(int value)
{
    ui->progressBar->setValue(value);
}

// Шкала выполнения задачи из второго потока
void MainWindow::changeValueProgressBar_2(int value)
{
    ui->progressBar_2->setValue(value);
}

// Шкала выполнения задачи из третьего потока
void MainWindow::changeValueProgressBar_3(int value)
{
    ui->progressBar_3->setValue(value);
}

// Шкала выполнения задачи из четвёртого потока
void MainWindow::changeValueProgressBar_4(int value)
{
    ui->progressBar_4->setValue(value);
}

// Шкала выполнения задачи из пятого потока
void MainWindow::changeValueProgressBar_5(int value)
{
    ui->progressBar_5->setValue(value);
}

// Шкала выполнения задачи из шестого потока
void MainWindow::changeValueProgressBar_6(int value)
{
    ui->progressBar_6->setValue(value);
}

// Шкала выполнения задачи из седьмого потока
void MainWindow::changeValueProgressBar_7(int value)
{
    ui->progressBar_7->setValue(value);
}

// Шкала выполнения задачи из восьмого потока
void MainWindow::changeValueProgressBar_8(int value)
{
    ui->progressBar_8->setValue(value);
}

// Шкала выполнения задачи из девятого потока
void MainWindow::changeValueProgressBar_9(int value)
{
    ui->progressBar_9->setValue(value);
}

// Шкала выполнения задачи из десятого потока
void MainWindow::changeValueProgressBar_10(int value)
{
    ui->progressBar_10->setValue(value);
}

// Запуск всех задач (потоков) одновременно
void MainWindow::on_pushButton_22_clicked()
{
    on_pushButton_clicked();
    on_pushButton_2_clicked();
    on_pushButton_3_clicked();
    on_pushButton_4_clicked();
    on_pushButton_5_clicked();
    on_pushButton_6_clicked();
    on_pushButton_7_clicked();
    on_pushButton_8_clicked();
    on_pushButton_9_clicked();
    on_pushButton_10_clicked();
}

// Запуск задачи в первом потоке
void MainWindow::on_pushButton_clicked() {
    mathTasks[0]->moveToThread(threads[0]); // Поместили задачу в поток
    if (mathTasks[0]->thread()->isRunning())
    {
        qDebug() << "Potok 0 worked";
        return;
    }
    threads[0]->start(); // Запускаем первую математическую задачу
    ui->progressBar->setValue(0); // Нулим шкалу

    emit startOperation(1, 1, 1, 20131552);
}

// Запуск задачи во втором потоке
void MainWindow::on_pushButton_2_clicked()
{
    mathTasks[1]->moveToThread(threads[1]); // Поместили задачу в поток
    if (mathTasks[1]->thread()->isRunning())
    {
        qDebug() << "Potok 1 worked";
        return;
    }
    threads[1]->start(); // Запускаем первую математическую задачу
    ui->progressBar_2->setValue(0); // Нулим шкалу
    emit startOperation_1(2, 2, 2, 20849330);
}

// Запуск задачи в третьем потоке
void MainWindow::on_pushButton_3_clicked()
{
    mathTasks[2]->moveToThread(threads[2]); // Поместили задачу в поток
    if (mathTasks[2]->thread()->isRunning())
    {
        qDebug() << "Potok 2 worked";
        return;
    }
    threads[2]->start(); // Запускаем первую математическую задачу
    ui->progressBar_3->setValue(0); // Нулим шкалу
    emit startOperation_2(3, 3, 3, 22711196);
}

// Запуск задачи в четвёртом потоке
void MainWindow::on_pushButton_4_clicked()
{
    mathTasks[3]->moveToThread(threads[3]); // Поместили задачу в поток
    if (mathTasks[3]->thread()->isRunning())
    {
        qDebug() << "Potok 3 worked";
        return;
    }
    threads[3]->start(); // Запускаем первую математическую задачу
    ui->progressBar_4->setValue(0); // Нулим шкалу
    emit startOperation_3(4, 4, 4, 25337735);
}

// Запуск задачи в пятом потоке
void MainWindow::on_pushButton_5_clicked()
{
    mathTasks[4]->moveToThread(threads[4]); // Поместили задачу в поток
    if (mathTasks[4]->thread()->isRunning())
    {
        qDebug() << "Potok 4 worked";
        return;
    }
    threads[4]->start(); // Запускаем первую математическую задачу
    ui->progressBar_5->setValue(0); // Нулим шкалу
    emit startOperation_4(5, 5, 5, 21629121);
}

// Запуск задачи в шестом потоке
void MainWindow::on_pushButton_6_clicked()
{
    mathTasks[5]->moveToThread(threads[5]); // Поместили задачу в поток
    if (mathTasks[5]->thread()->isRunning())
    {
        qDebug() << "Potok 5 worked";
        return;
    }
    threads[5]->start(); // Запускаем первую математическую задачу
    ui->progressBar_6->setValue(0); // Нулим шкалу
    emit startOperation_5(6, 6, 6, 19947349);
}

// Запуск задачи в седьмом потоке
void MainWindow::on_pushButton_7_clicked()
{
    mathTasks[6]->moveToThread(threads[6]); // Поместили задачу в поток
    if (mathTasks[6]->thread()->isRunning())
    {
        qDebug() << "Potok 6 worked";
        return;
    }
    threads[6]->start(); // Запускаем первую математическую задачу
    ui->progressBar_7->setValue(0); // Нулим шкалу
    emit startOperation_6(7, 7, 7, 18143029);
}

// Запуск задачи в восьмом потоке
void MainWindow::on_pushButton_8_clicked()
{
    mathTasks[7]->moveToThread(threads[7]); // Поместили задачу в поток
    if (mathTasks[7]->thread()->isRunning())
    {
        qDebug() << "Potok 7 worked";
        return;
    }
    threads[7]->start(); // Запускаем первую математическую задачу
    ui->progressBar_8->setValue(0); // Нулим шкалу
    emit startOperation_7(115.231, 115.231, 115.231, 22263052);
}

// Запуск задачи в девятом потоке
void MainWindow::on_pushButton_9_clicked()
{
    mathTasks[8]->moveToThread(threads[8]); // Поместили задачу в поток
    if (mathTasks[8]->thread()->isRunning())
    {
        qDebug() << "Potok 8 worked";
        return;
    }
    threads[8]->start(); // Запускаем первую математическую задачу
    ui->progressBar_9->setValue(0); // Нулим шкалу
    emit startOperation_8(0.12, 0.12, 0.12, 23531858);
}

// Запуск задачи в десятом потоке
void MainWindow::on_pushButton_10_clicked()
{
    mathTasks[9]->moveToThread(threads[9]); // Поместили задачу в поток
    if (mathTasks[9]->thread()->isRunning())
    {
        qDebug() << "Potok 9 worked";
        return;
    }
    threads[9]->start(); // Запускаем первую математическую задачу
    ui->progressBar_10->setValue(0); // Нулим шкалу
    emit startOperation_9(112, 112, 112, 22243662);
}
