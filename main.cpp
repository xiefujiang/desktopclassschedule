#include "layer_class.h"

#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QSettings>
#include <QResource>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    layer_class w;
    config c;       //配置窗口的类

    w.show();

    //创建系统托盘
    static bool isshowed = true;
    QSystemTrayIcon tray = new QSystemTrayIcon();

    QIcon icon = QIcon(":/icon/res/icon.jpg");
    tray.setIcon(icon);
    tray.setToolTip(QString::fromLocal8Bit("课程表"));
    QMenu *menu = new QMenu();
    QAction *show = new QAction("显示/隐藏");
    QAction *exit = new QAction("退出");
    QAction *config = new QAction("配置...");
    menu->addAction(config);
    menu->addAction(show);
    menu->addAction(exit);
    tray.setContextMenu(menu);
    tray.show();
    QObject::connect(show, &QAction::triggered, [&](){
        if(isshowed)
        {
            w.hide();
        }
        else
        {
            w.show();
        }
        isshowed = !isshowed;
    });
    QObject::connect(exit,&QAction::triggered, [&](){
        QApplication::quit();
    });
    QObject::connect(config,&QAction::triggered, [&](){
        c.show();
    });
    tray.show();


    //创建配置文件


    return a.exec();
}
