#ifndef LASER_REV_H
#define LASER_REV_H

#include "mainwindow.h"
#include <iostream>
#include <string>

#include <QApplication>
#include <QThread>
#include <QObject>
#include "laser_receiver1/rplidar_result.h"

using namespace std;

class Laser_infomation : public QThread
{
Q_OBJECT
public:
	void run();

};

class SignalinQt:public QObject
{
    Q_OBJECT
public:
    SignalinQt(){DofRplidar=6.0;}
    void setvalue(float num);
    float getvalue(void);
    void SendSignal(void);
signals:
    void SendRange(void);
private:
    float DofRplidar;
};

 extern SignalinQt aa;
 extern float range_min;
 extern laser_receiver1::rplidar_result process_result;
#endif
