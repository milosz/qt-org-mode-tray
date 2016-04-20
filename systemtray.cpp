#include "systemtray.h"
#include "ui_systemtray.h"

#include "ideadialog.h"
#include "tododialog.h"

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
    IdeaDialog dialog;
    dialog.exec();
}

void SystemTray::openToDoDialog()
{
    TodoDialog dialog;
    dialog.exec();
}

void SystemTray::openBkmkDialog()
{
    qDebug("Add a bookmark");
}
