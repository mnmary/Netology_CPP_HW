#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent) : QObject{parent}
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StopWatch::timeoutTimer);//по истечению времени таймера вызываем процедуру
}

void StopWatch::start()
{
    oldCntMs = 0;
    timer->start(10);//запускаем таймер на 0.1 секунду
}

void StopWatch::stop()
{
    timer->stop();//останавливаем таймер
}

void StopWatch::reset()
{
    //сбрасываем счетчики, но не останавливаем таймер
    cntMs = 0;
    oldCntMs = 0;
    emit sig_timeoutTimer(cntMs);//передаем сигнал
}

void StopWatch::timeoutTimer()
{
    //таймаут
    cntMs += 10;  //счетчик милисекунд увеличиваем на 10мс
    emit sig_timeoutTimer(cntMs);//передаем сигнал
}

QString StopWatch::milisecondsToString(int ms)
{
    int ms1 = ms;
    int seconds = ms1 / 1000;
    ms1 %= 1000;

    int minutes = seconds / 60;
    seconds %= 60;

    int hours = minutes / 60;
    minutes %= 60;

    return QString::number(hours) + ':' + QString::number(minutes) + ':' + QString::number(seconds) + '.' + QString::number(ms1);
}

QString StopWatch::calcTime()
{
    return milisecondsToString(cntMs);
}

QString StopWatch::ringTime()
{
    ringCntMs = cntMs - oldCntMs;
    oldCntMs = cntMs;
    return milisecondsToString(ringCntMs);
}

