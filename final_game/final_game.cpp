#include "final_game.h"
#include "wirpi.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QTimer>

QTimer *timerNew= new QTimer();
int moveX=0, moveY=0;

final_game::final_game(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Test object start";
    // WirPi wirpi;
    timer_start();
    QObject::connect(timerNew, &QTimer::timeout, this, &final_game::movingVar);
}


void final_game::displayText(const QString &s){
    QString displayString=s;
    //emit sendMess2(displayString);
    qDebug() << "trying to read string from QML: "<< displayString;

}

double final_game::movingSpeedX(double x){

    double disX=x*moveX;
    return disX;
}


double final_game::movingSpeedY(double y){

    double disY=y*moveY;
    return disY;
}

double final_game::xCheck(double x){
    if (x>1920){
        x=1920;
    }
    else if (x<0){
        x=0;
    }
    return x;
}

double final_game::yCheck(double y){
    if (y>972){
        y=1920;
    }
    else if (y<0){
        y=0;
    }
    return y;
}

void  final_game::movingVar(){
    moveX++;
    moveY++;
}

void final_game::flying(){
    timerNew->start(500);
}


void final_game::stopping(){
    timerNew->stop();
    moveX=0;
    moveY=0;
}



void final_game::someSlot_tmr_start()
{
    //timer_start();
    qDebug() << " slot 1";
}


void final_game::timer_start()
{
  QTimer::singleShot(1 * 1000, this, SLOT(timer_do()));

      qDebug() << " Timer started ";

}

void final_game::timer_do()
{
    qDebug() << " Timer tick";

    ad_valx=wirpi.Read_sensor0()*100.0/800000;   // x value of joystick
    ad_valy=wirpi.Read_sensor1()*100.0/800000;   // y value of joystick


    QString str1=" ";
    str1.sprintf("%+02.2f",double(ad_valx));
    QString nText1 = "AD= "+ str1;

    QString str2=" ";
    str2.sprintf("%+02.2f",double(ad_valy));
    QString nText2 = "AD= "+ str2;

    emit someSignal_tbox1(nText1);
    emit someSignal_tbox2(nText2);


    QTimer::singleShot(1 * 100, this, SLOT(timer_do()));  // re shoot timer

}





