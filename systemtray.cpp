#include "systemtray.h"
#include "ui_systemtray.h"

SystemTray::SystemTray(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemTray)
{
    ui->setupUi(this);
}

SystemTray::~SystemTray()
{
    delete ui;
}
