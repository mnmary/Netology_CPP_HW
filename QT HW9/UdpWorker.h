#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>


#define BIND_PORT_TIME 12345
#define BIND_PORT_DG 23456

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);

    void TimeInitSocket(void );
    void SendTimeDatagram(QByteArray data );
    void TimeReadDatagram( QNetworkDatagram datagram);

    void DGInitSocket(void  );
    void SendDatagram(QByteArray data);
    void ReadDatagram( QNetworkDatagram datagram);


private slots:
    void time_readPendingDatagrams(void );
    void DG_readPendingDatagrams(void );

private:
    QUdpSocket* timeserviceUdpSocket;
    QUdpSocket* DGserviceUdpSocket;

signals:
    void sig_sendtimeDataToGUI( QByteArray time_data);
    void sig_sendDatagramToGUI( QByteArray str_data, QNetworkDatagram datagram);
};

#endif // UDPWORKER_H
