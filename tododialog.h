#ifndef TODODIALOG_H
#define TODODIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class TodoDialog;
}

class TodoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TodoDialog(QWidget *parent = 0);
    ~TodoDialog();

private slots:
    void on_buttonBoxTodo_accepted();

private:
    Ui::TodoDialog *ui;
};

#endif // TODODIALOG_H
