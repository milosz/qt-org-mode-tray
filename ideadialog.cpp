#include "ideadialog.h"
#include "ui_ideadialog.h"

IdeaDialog::IdeaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdeaDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    move(1920-width(),20);
}

IdeaDialog::~IdeaDialog()
{
    delete ui;
}

void IdeaDialog::on_buttonBoxIdea_accepted()
{
    QString title, desc, source;

    title=ui->plainTextEditIdeaTitle->text();
    desc=ui->plainTextEditIdeaDesc->toPlainText();
    source=ui->plainTextEditIdeaTags->text();

    if(source.length() == 0)
        source.append("general");

    title=title.simplified();
    title=title.replace("/","%2F");
    source=source.simplified();
    source=source.replace("/","%2F");
    desc=desc.replace("/","%2F");

    QProcess::startDetached("/home/milosz/.emacs.d/org-add-idea.sh", QStringList() << qPrintable(title)  << qPrintable(source)  << qPrintable(desc));
}
