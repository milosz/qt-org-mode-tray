#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QWidget>

namespace Ui {
class SystemTray;
}

class SystemTray : public QWidget
{
    Q_OBJECT

public:
    explicit SystemTray(QWidget *parent = 0);
    ~SystemTray();

private:
    Ui::SystemTray *ui;
};

#endif // SYSTEMTRAY_H
