#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_stop->setEnabled(false);

    udpWorker = new UDPworker(this);
    udpWorker->TimeInitSocket();

    connect(udpWorker, &UDPworker::sig_sendtimeDataToGUI, this, &MainWindow::TimePorcessReceiveData);

    //добавим для отправки своей датаграммы
    udpWorkerDg = new UDPworker(this);
    udpWorkerDg->DGInitSocket();
    //свяжем сигнал с обработчиком
    connect(udpWorkerDg, &UDPworker::sig_sendDatagramToGUI, this, &MainWindow::datagramReceiveData);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [&]{

        QDateTime dateTime;
        dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        dataToSend.resize(sizeof(dateTime));

        memcpy(dataToSend.data(), &dateTime, sizeof(dateTime));
        udpWorker->SendTimeDatagram(dataToSend);
        timer->start(TIMER_DELAY);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
    ui->pb_start->setEnabled(false);
    ui->pb_stop->setEnabled(true);
}

void MainWindow::TimePorcessReceiveData(QByteArray data)
{
    counterPck++;
    QDateTime rcvDateTime;

        memcpy(&rcvDateTime, data.data(), sizeof(rcvDateTime));

         if(counterPck % 20 == 0){
             ui->te_result->clear();
         }


         ui->te_result->append("Текущее время: " +rcvDateTime.toString() + ". "
                    "Принято пакетов " + QString::number(counterPck));

}

//обработчик сигнала датаграммы
void MainWindow::datagramReceiveData(QByteArray data, QNetworkDatagram datagram)
{
    counterPck++;
    QString str;

         memcpy(&str, data.data(), sizeof(str));

         if(counterPck % 20 == 0){
             ui->te_result->clear();
         }


         ui->te_result->append(" Принято сообщение от: " + datagram.senderAddress().toString() + ", "
                     "размер сообщения " + QString::number(str.size()) );

}

void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
    ui->pb_stop->setEnabled(false);
    ui->pb_start->setEnabled(true);
}


//отправляем датаграмму
void MainWindow::on_pb_datagram_clicked()
{
    ui->te_result->clear();


    QString str = ui->te->toPlainText();

    QByteArray datastr;
    datastr.resize(sizeof(str));
    memcpy(datastr.data(), &str, sizeof(str));

    udpWorkerDg->SendDatagram(datastr);
    ui->te->clear();
}

