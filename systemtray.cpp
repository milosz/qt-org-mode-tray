#include "systemtray.h"
#include "ui_systemtray.h"

#include <QtGui>

SystemTray::SystemTray(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemTray)
{
    ui->setupUi(this);

    createActions();
    createTrayIcon();
    trayIcon->show();
}

SystemTray::~SystemTray()
{
    delete ui;
}

void SystemTray::createActions(){
    ideaAction=new QAction(tr("Add an &idea"),this);
    connect(ideaAction,SIGNAL(triggered()),this,SLOT(openIdeaDialog()));
    quitAction=new QAction(tr("&Close"),this);
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
}

void SystemTray::createTrayIcon(){
    trayIconMenu=new QMenu(this);
    trayIconMenu->addAction(ideaAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon=new QSystemTrayIcon(this);
    QIcon icon("E");
    trayIcon->setIcon(icon);

    trayIcon->setContextMenu(trayIconMenu);
}

void SystemTray::openIdeaDialog()
{
    qDebug("Add an idea");
}
