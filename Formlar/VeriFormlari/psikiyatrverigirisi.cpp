#include "psikiyatrverigirisi.h"
#include "ui_psikiyatrverigirisi.h"

PsikiyatrVeriGirisi::PsikiyatrVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PsikiyatrVeriGirisi)
{
    ui->setupUi(this);
}

PsikiyatrVeriGirisi::~PsikiyatrVeriGirisi()
{
    delete ui;
}


void PsikiyatrVeriGirisi::ekranGuncelle()
{
   ui->leAdi_2->setText(_veri->ad());
}

void PsikiyatrVeriGirisi::veriGuncelle()
{
}
