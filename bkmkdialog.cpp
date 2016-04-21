#include "bkmkdialog.h"
#include "ui_bkmkdialog.h"

BkmkDialog::BkmkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BkmkDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    move(1920-width(),20);
}

BkmkDialog::~BkmkDialog()
{
    delete ui;
}

void BkmkDialog::on_buttonBoxBkmk_accepted()
{
    QString title, desc, source;

    title=ui->plainTextEditBkmkTitle->text();
    desc=ui->plainTextEditBkmkDesc->toPlainText();
    source=ui->plainTextEditBkmkSrc->text();

    if(source.length() == 0)
        source.append("missing");

    title=title.simplified();
    title=title.replace("/","%2F");
    source=source.replace("/","%2F");
    desc=desc.replace("/","%2F");

    QProcess::startDetached("/home/milosz/.emacs.d/org-add-bookmark.sh", QStringList() << qPrintable(source)  << qPrintable(title)  << qPrintable(desc));
}
