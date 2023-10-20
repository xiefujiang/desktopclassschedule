#include "config.h"
#include "ui_config.h"

#include <QStandardItemModel>
#include <QSettings>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QDebug>
#include <QProcess>

config::config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint,true);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowIcon(QIcon("D:/Projects/Qt_layer/icon.jpg"));
    this->setWindowTitle("课程表配置");


    ui->table->setShowGrid(true);
    ui->table->setSortingEnabled(false);
    QStandardItemModel* model = new QStandardItemModel();
    QStringList label = QObject::tr("周一,周二,周三,周四,周五,周六,周日").split(",");
    QStringList num = QObject::tr("1,2,3,4,5,6,7,8,晚1,晚2,晚3,晚4").split(",");
    model->setHorizontalHeaderLabels(label);
    model->setVerticalHeaderLabels(num);
                //setItem(行，列，item);
    QStandardItem* item = 0;
    //for (int q = 0; q < 7; q++){
    //for (int j = 0; j < 12; j++) {
    //    item = new QStandardItem(QString("语文"));
    //    model->setItem(j,q,item);
    //}
    //}

    //读取cfg
    QString fileName;
    fileName = QCoreApplication::applicationDirPath();
    fileName += "/config/cfg.ini";
    QSettings settings(fileName, QSettings::IniFormat);
    QStringList less = QObject::tr("les1,les2,les3,les4,les5,les6,les7,les8,les9,les10,les11,les12").split(",");
    QStringList week = QObject::tr("Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday").split(",");
    for(int i=0;i<7;i++)
    {
        settings.beginGroup(week[i]);
        for(int j=0;j<12;j++)
        {
            item = new QStandardItem(settings.value(less[j]).toString());
            model->setItem(j,i,item);
        }
        settings.endGroup();
    }

    ui->table->setModel(model);
    ui->table->show();
}

config::~config()
{
    delete ui;
}




void config::on_cancel_clicked()
{
    this->hide();
}


void config::on_save_clicked()
{
    QString fileName;
    fileName = QCoreApplication::applicationDirPath();
    fileName += "/config/cfg.ini";
    QSettings settings(fileName, QSettings::IniFormat);
    QModelIndex index;// = ui->table->model()->index(0,1);
    QString str;// = ui->table->model()->data(index).toString();
    //settings.beginGroup("Monday");
    //settings.setValue("les1",str);
    QStringList less = QObject::tr("les1,les2,les3,les4,les5,les6,les7,les8,les9,les10,les11,les12").split(",");
    QStringList week = QObject::tr("Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday").split(",");
    for(int j=0; j<7;j++){
    settings.beginGroup(week[j]);
    for(int i=0;i<12;i++)
    {
    index = ui->table->model()->index(i,j);
    str = ui->table->model()->data(index).toString();
    settings.setValue(less[i],str);
    }
    settings.endGroup();
    }
    this->hide();

    qApp->quit();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

