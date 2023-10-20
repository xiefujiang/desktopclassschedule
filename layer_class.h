#ifndef LAYER_CLASS_H
#define LAYER_CLASS_H

#include <QWidget>
#include <QStandardItemModel>

#include "config.h"

QT_BEGIN_NAMESPACE
namespace Ui { class layer_class; }
QT_END_NAMESPACE

class layer_class : public QWidget
{
    Q_OBJECT

public:
    layer_class(QWidget *parent = nullptr);
    ~layer_class();

public:
    config *config_class;   //配置窗口的类
    //QStandardItemModel *readcfg();

private:
    Ui::layer_class *ui;

public slots:
    void timerUpate(void);
};
#endif // LAYER_CLASS_H
