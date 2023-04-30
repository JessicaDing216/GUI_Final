#ifndef WIRPI_H
#define WIRPI_H

#include <QObject>
#include <QWidget>


class WirPi
{
private:

    int I2C_addr;

public:


    WirPi();

    int Read_sensor0(void);
    int Read_sensor1(void);

    int Read_ad(unsigned char ch);

};



#endif // WIRPI_H
