#include "doktorverigirisi.h"
#include "ui_doktorverigirisi.h"

DoktorVeriGirisi::DoktorVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoktorVeriGirisi)
{
    ui->setupUi(this);
}

DoktorVeriGirisi::~DoktorVeriGirisi()
{
    delete ui;
}
