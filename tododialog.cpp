#include "tododialog.h"
#include "ui_tododialog.h"

TodoDialog::TodoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodoDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    move(1920-width(),20);
}

TodoDialog::~TodoDialog()
{
    delete ui;
}

void TodoDialog::on_buttonBoxTodo_accepted()
{
    QString title, desc;

    title=ui->plainTextEditTodoTitle->text();
    desc=ui->plainTextEditTodoDesc->toPlainText();

    title=title.simplified();
    title=title.replace("/","%2F");
    desc=desc.replace("/","%2F");

    QProcess::startDetached("/home/milosz/.emacs.d/org-add-todo.sh", QStringList() << qPrintable(title)  << "trayicon"  << qPrintable(desc));
}
