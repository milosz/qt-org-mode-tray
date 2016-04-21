#ifndef BKMKDIALOG_H
#define BKMKDIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class BkmkDialog;
}

class BkmkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BkmkDialog(QWidget *parent = 0);
    ~BkmkDialog();

private slots:
    void on_buttonBoxBkmk_accepted();

private:
    Ui::BkmkDialog *ui;
};

#endif // BKMKDIALOG_H
