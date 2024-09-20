#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeoutTimer(int cntMs);
    void btnStartStop_clicked(bool checked);
    void resetBtn_clicked(bool checked);
    void circleBtn_clicked(bool checked);
private:

    Ui::MainWindow *ui;
    StopWatch *timer;
    int cntCircle {0};
};
#endif // MAINWINDOW_H
