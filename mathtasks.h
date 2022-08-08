#ifndef MATHTASKS_H
#define MATHTASKS_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QtMath>

class MathTasks : public QObject
{
    Q_OBJECT // Можем использовать сигналы и слоты

public:
    explicit MathTasks(QObject *parent = nullptr); // Запрещаем неявное преобразование
    ~MathTasks();

private:
    MathTasks(const MathTasks&) = delete; // Не нужно, удаляем
    void operator=(const MathTasks&) = delete; // Не нужно, удаляем
    void FeatureMinimum(double, double, double, int); // Алгоритм наискорейшего спуска

private:
    double a = 0.000001; // значение шага
    double e = 0.000001; // максимальная погрешность

public slots:
    void Task(double, double, double, int); // Задача для потоков

signals:
    void ChangeProgressBar(const int value = 1); // Для изменения шкалы в MainWindow

};

#endif // MATHTASKS_H
