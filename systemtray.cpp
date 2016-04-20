#include "systemtray.h"
#include "ui_systemtray.h"

#include <QtGui>

SystemTray::SystemTray(QWidget *parent) :
    QWidget(parent)
{
    createActions();
    createTrayIcon();

}

SystemTray::~SystemTray() {}

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

void SystemTray::show() {
    trayIcon->show();
}

void SystemTray::openIdeaDialog()
{
    qDebug("Add an idea");
}
