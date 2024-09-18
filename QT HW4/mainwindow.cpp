#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Исходное состояние виджетов
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::pushButton_clicked);

    ui->radioButton->setChecked(true);
    ui->radioButton->setText("Программное имя 1");
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setText("Программное имя 2");
    ui->comboBox->addItem("Прогрмаммно добавленный 1");
    ui->comboBox->addItem("Прогрмаммно добавленный 2");
    ui->comboBox->addItem("Прогрмаммно добавленный 3");
    ui->comboBox->addItem("Прогрмаммно добавленный 4");
    ui->comboBox->setCurrentIndex(2);
    ui->pushButton->setCheckable(true);
    ui->pushButton->setText("Изменена надпись программно");
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setMinimum(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::pushButton_clicked(bool checked)
{
    if (ui->progressBar->value() == 10)
    {
       ui->progressBar->setValue(0);
    }
    ui->progressBar->setValue(ui->progressBar->value()+1);
    qDebug() << Q_FUNC_INFO << "";
}

