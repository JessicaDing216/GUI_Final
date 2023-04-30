#ifndef final_game_H
#define final_game_H

#include <QObject>
#include <QWidget>
#include "wirpi.h"


class final_game:public QObject
{
    //value to store ad input
    float ad_valx=0; //ch 0
    float ad_valy=0; //ch 1

    Q_OBJECT

public:
   explicit final_game(QObject *parent = 0);
    WirPi wirpi;
    void timer_start();

public slots:
    void displayText(const QString &s);
    double movingSpeedX(double x);
    double movingSpeedY(double y);
    double xCheck(double x);
    double yCheck(double y);
    void movingVar();
    void flying();
    void stopping();
    void someSlot_tmr_start();

private slots:

    void timer_do();

signals:
    void sendMessMove(const double &x_value, const double &y_value);
    void sendMess(const QString &gauge_value);
    void someSignal_tbox1(const QString &text_tbox1);
    void someSignal_tbox2(const QString &text_tbox2);

};

#endif // final_game_H









