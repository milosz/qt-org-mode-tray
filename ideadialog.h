#ifndef IDEADIALOG_H
#define IDEADIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class IdeaDialog;
}

class IdeaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IdeaDialog(QWidget *parent = 0);
    ~IdeaDialog();

private slots:
    void on_buttonBoxIdea_accepted();

private:
    Ui::IdeaDialog *ui;
};

#endif // IDEADIALOG_H
