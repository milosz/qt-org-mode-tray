#include "systemtray.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(false);

    SystemTray w;
    w.show();

    return a.exec();
}
