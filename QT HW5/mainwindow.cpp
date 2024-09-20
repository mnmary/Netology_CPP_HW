#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Исходное состояние виджетов
    ui->setupUi(this);

    ui->btnStartStop->setCheckable(true);

    cntCircle = 0;
    timer = new StopWatch(this);

    //источник - элемент, источник - сигнал, приемник - элемент, приемник - обработчик
    connect(timer, &StopWatch::sig_timeoutTimer, this, &MainWindow::timeoutTimer);

    connect(ui->btnStartStop, &QPushButton::clicked, this, &MainWindow::btnStartStop_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetBtn_clicked);
    connect(ui->circleButton, &QPushButton::clicked, this, &MainWindow::circleBtn_clicked);

 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::timeoutTimer(int cntMs)
{
    //qDebug() << Q_FUNC_INFO << "" << cntMs;
    ui->lblTimer->setText(timer->calcTime());
}

void MainWindow::btnStartStop_clicked(bool checked)
{
    if (!checked)
    {
        ui->btnStartStop->setText("Старт");
        timer->stop();
    }
    else
    {
        ui->btnStartStop->setText("Пауза");
        timer->start();
    }
}

void MainWindow::resetBtn_clicked(bool checked)
{
    timer->reset();
}

void MainWindow::circleBtn_clicked(bool checked)
{
    cntCircle ++;
    ui->circleLog->append("Круг: " + QString::number(cntCircle)+" время: "+timer->ringTime());
}
