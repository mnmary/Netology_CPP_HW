#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}

//TIME
void UDPworker::TimeInitSocket( )
{

    timeserviceUdpSocket = new QUdpSocket(this);

    timeserviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT_TIME);

    connect(timeserviceUdpSocket,  &QUdpSocket::readyRead, this, &UDPworker::time_readPendingDatagrams);

}

void UDPworker::SendTimeDatagram(QByteArray data)
{
    timeserviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_TIME);
}

void UDPworker::TimeReadDatagram(QNetworkDatagram datagram)
{

    QByteArray time_data;

    time_data.resize(datagram.data().size());
    time_data = datagram.data();

    emit sig_sendtimeDataToGUI(time_data);

}

void UDPworker::time_readPendingDatagrams( void )
{
    while(timeserviceUdpSocket->hasPendingDatagrams())
    {
            QNetworkDatagram datagram = timeserviceUdpSocket->receiveDatagram();

            TimeReadDatagram(datagram);
    }

}


//DATAGRAM
void UDPworker::DGInitSocket( )
{

    DGserviceUdpSocket = new QUdpSocket(this);

    DGserviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT_DG);

    connect(DGserviceUdpSocket,  &QUdpSocket::readyRead, this, &UDPworker::DG_readPendingDatagrams);

}

void UDPworker::SendDatagram(QByteArray data)
{
    DGserviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_DG);
}

void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray str_data;

    str_data.resize(datagram.data().size());
    str_data = datagram.data();

    emit sig_sendDatagramToGUI(str_data,datagram);

}

void UDPworker::DG_readPendingDatagrams( void )
{
    while(DGserviceUdpSocket->hasPendingDatagrams())
    {
            QNetworkDatagram datagram = DGserviceUdpSocket->receiveDatagram();

            ReadDatagram(datagram);
    }

}
