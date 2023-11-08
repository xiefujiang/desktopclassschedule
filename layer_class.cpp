#include "layer_class.h"
#include "ui_layer_class.h"
#include <QFont>
#include <QTimer>
#include <qdatetime.h>
#include <QLocale>
#include <QRect>
#include <QSystemTrayIcon>      //系统托盘头文件
#include <QAction>
#include <QMenu>
#include <QFile>
#include <QSettings>
#include <QStandardItemModel>
#include <QDebug>
#include<QScreen>

layer_class::layer_class(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::layer_class)
{
    ui->setupUi(this);
    //隐藏标题栏、设置固定大小、设置背景透明
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setFixedSize(115,630);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    QScreen *screen=QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry() ;
    int screen_width = mm.width();
    int screen_height = mm.height();
    //move(1810,200);1920,1080
    move(screen_width-110,(int)(screen_height/2)-315);
    //保持窗口总在最前
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowFlags(this->windowFlags() | Qt::WindowTransparentForInput | Qt::ToolTip);

    //设置定时器，实时显示时间
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpate()));

    //读取文件！！不要写
    QDate currentDate = QDate::currentDate();
    int dayOfWeek = currentDate.dayOfWeek();
    QString fileName;
    fileName = QCoreApplication::applicationDirPath();
    fileName += "/config/cfg.ini";
    QSettings settings(fileName, QSettings::IniFormat);
    //settings.beginGroup("test");
    //settings.setValue("les1","Chinese");
    //settings.endGroup();
    //settings.beginGroup("test");
    //ui->les1->setText(settings.value("les1").toString());
    if(dayOfWeek==1)
    {
        settings.beginGroup("Monday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }
    else if(dayOfWeek==2)
    {
        settings.beginGroup("Tuesday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }
    else if(dayOfWeek==3)
    {
        settings.beginGroup("Wednesday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }
    else if(dayOfWeek==4)
    {
        settings.beginGroup("Thursday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }
    else if(dayOfWeek==5)
    {
        settings.beginGroup("Friday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }
    else if(dayOfWeek==6)
    {
        settings.beginGroup("Saturday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }
    else if(dayOfWeek==7)
    {
        settings.beginGroup("Sunday");
        ui->les1->setText(settings.value("les1").toString());
        ui->les2->setText(settings.value("les2").toString());
        ui->les3->setText(settings.value("les3").toString());
        ui->les4->setText(settings.value("les4").toString());
        ui->les5->setText(settings.value("les5").toString());
        ui->les6->setText(settings.value("les6").toString());
        ui->les7->setText(settings.value("les7").toString());
        ui->les8->setText(settings.value("les8").toString());
        ui->les9->setText(settings.value("les9").toString());
        ui->les10->setText(settings.value("les10").toString());
        ui->les11->setText(settings.value("les11").toString());
        ui->les12->setText(settings.value("les12").toString());
        settings.endGroup();
    }


    //高考倒计时
    QDateTime time1 = QDateTime::fromString("2024-06-07 00:00:00", "yyyy-MM-dd hh:mm:ss");
    //QDateTime time2 = QDateTime::fromString("2020-11-26 16:43:02", "yyyy-MM-dd    hh:mm:ss");
    QDateTime time2 = QDateTime::currentDateTime();
    int days = -(time1.daysTo(time2));
    QString tim=QString::number(days);
    tim += "天";
    ui->time_to_study->setText(tim);

    ui->l1->setStyleSheet("border-top-left-radius:10%;width:15px;height:35px;background-color:rgb(255,170,255);");
    ui->l12->setStyleSheet("border-bottom-left-radius:10%;width:15px;height:35px;background-color: rgb(0, 85, 255);");
}

layer_class::~layer_class()
{
    delete ui;
}





void layer_class::timerUpate(void)
{
    //设置为中国时间
    QLocale loc(QLocale::Chinese,QLocale::China);
    QDateTime ti = QDateTime::currentDateTime();

    QString str_time = ti.toString("hh:mm:ss");
    QString str_date = ti.toString("yyyy/MM/dd");
    QString str_week = loc.toString(ti,"dddd");
    ui->time->setText(str_time);
    ui->date->setText(str_date);
    ui->weekly->setText(str_week);

}

