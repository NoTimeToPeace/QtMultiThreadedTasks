#include "mathtasks.h"
#include "mainwindow.h"

MathTasks::MathTasks(QObject *parent): QObject{parent} {
    qDebug() << "Constructor MathTasks";
}

// Метод наискорейшего спуска
void MathTasks::FeatureMinimum(double x1, double x2, double x3, int iteration)
{
    double f = 1;
    double dfdx1 = 1;
    double dfdx2 = 2;
    double dfdx3 = 1;
    int i = 2;
    while (1) {
        f = qPow(x1, 4) + qPow(x2, 2) + qPow(x3, 2) + x1 * x2 + x2 * x3;
        dfdx1 = 4 * qPow(x1, 3) + x2;
        dfdx2 = 2 * x2 + x1 + x3;
        dfdx3 = 2 * x3 + x2;
        if (qFabs(dfdx1) <= e && qFabs(dfdx2) <= e && qFabs(dfdx3) <= e) {
            break;
        }
        x1 = x1 - a * dfdx1;
        x2 = x2 - a * dfdx2;
        x3 = x3 - a * dfdx3;
        i++;
        if (i % int(iteration/100) == 0) {
            emit ChangeProgressBar(i / int(iteration/100));
        }
    }
    qDebug() << "Answer: " << f;
}

// Задача для потоков
void MathTasks::Task(double x1, double x2, double x3, int iteration) {
    qDebug() << "Thread" << this->thread();
    FeatureMinimum(x1, x2, x3, iteration);
    this->thread()->quit();
}

MathTasks::~MathTasks() {
    qDebug() << "Destructor MathTasks";
}
