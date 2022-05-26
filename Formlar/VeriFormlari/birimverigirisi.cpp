#include "birimverigirisi.h"
#include "ui_birimverigirisi.h"

BirimVeriGirisi::BirimVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BirimVeriGirisi)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this,SIGNAL(veriKaydet()));
}

BirimVeriGirisi::~BirimVeriGirisi()
{
    delete ui;
}

void BirimVeriGirisi::ekranGuncelle()
{
    ui->leBirimAdi->setText(_veri->birimAdi());
    ui->leBirimKodu->setText(_veri ->birimKodu());
    ui->leTelefon->setText(_veri->birimIletisim());
    ui->teAdresi->setText(_veri->birimAdresi());
}

void BirimVeriGirisi::veriGuncelle()
{
    _veri->setBirimAdi(ui->leBirimAdi->text());
    _veri->setBirimAdresi(ui->teAdresi->toPlainText());
    _veri->setBirimIletisim(ui->leTelefon->text());
    _veri->setBirimKodu(ui->leBirimKodu->text());
}
