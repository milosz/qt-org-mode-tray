#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>

namespace Ui {
class SystemTray;
}

class SystemTray : public QWidget
{
    Q_OBJECT

public:
    explicit SystemTray(QWidget *parent = 0);
    ~SystemTray();

private slots:
    void openIdeaDialog();

private:
    Ui::SystemTray *ui;
    QAction *ideaAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    void createActions();
    void createTrayIcon();

};

#endif // SYSTEMTRAY_H
