#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>

class SystemTray : public QWidget
{
    Q_OBJECT

public:
    void show();
    explicit SystemTray(QWidget *parent = 0);
    ~SystemTray();

private slots:
    void openIdeaDialog();
    void openToDoDialog();
    void openBkmkDialog();

private:
    QAction *ideaAction;
    QAction *todoAction;
    QAction *bkmkAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    void createActions();
    void createTrayIcon();
};

#endif // SYSTEMTRAY_H
