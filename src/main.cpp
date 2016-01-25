#include "mainwindow.h"
#include <QApplication>
#include "ros/ros.h"
#include "laser_rev.h"
#include "laser_receiver1/rplidar_result.h"
#include <QTextCodec>

Laser_infomation information;
SignalinQt aa;
float range_min=6;
laser_receiver1::rplidar_result process_result;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //中文字符设置
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    MainWindow w;
    w.showMaximized();//最大化显示

    ros::init(argc,argv,"laser_rev");
    information.start();

    return a.exec();
}
