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
    todoAction=new QAction(tr("Add a &todo"),this);
    connect(todoAction,SIGNAL(triggered()),this,SLOT(openToDoDialog()));
    bkmkAction=new QAction(tr("Add a &bookmark"),this);
    connect(bkmkAction,SIGNAL(triggered()),this,SLOT(openBkmkDialog()));
    quitAction=new QAction(tr("&Close"),this);
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
}

void SystemTray::createTrayIcon(){
    trayIconMenu=new QMenu(this);
    trayIconMenu->addAction(ideaAction);
    trayIconMenu->addAction(todoAction);
    trayIconMenu->addAction(bkmkAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon=new QSystemTrayIcon(this);
    QIcon icon(":/icon.png");
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

void SystemTray::openToDoDialog()
{
    qDebug("Add a todo");
}

void SystemTray::openBkmkDialog()
{
    qDebug("Add a bookmark");
}
