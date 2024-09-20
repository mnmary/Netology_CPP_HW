#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT

public:
    explicit StopWatch(QObject *parent = nullptr);

    //методы, доступные вызывающей форме
    void start();
    void stop();
    void reset();

    //обработчики событии таймера
    void timeoutTimer();//обработка таймаута
    QString calcTime();
    QString ringTime();

signals:
    //сигналы наружу для вызывающей формы
    void sig_timeoutTimer(int cntMs);

private:
    QTimer* timer;
    int cntMs {0};//счетчик милисекунд
    int ringCntMs {0};
    int oldCntMs {0};
    QString milisecondsToString(int ms);
};

#endif // STOPWATCH_H
