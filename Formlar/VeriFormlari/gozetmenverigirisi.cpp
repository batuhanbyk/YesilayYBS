    #include "gozetmenverigirisi.h"
#include "ui_gozetmenverigirisi.h"

GozetmenVeriGirisi::GozetmenVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GozetmenVeriGirisi)
{
    ui->setupUi(this);
}

GozetmenVeriGirisi::~GozetmenVeriGirisi()
{
    delete ui;
}


void GozetmenVeriGirisi::ekranGuncelle()
{
    ui->leAdi->setText(_veri->ad());
    ui->leSoyadi->setText(_veri->soyad());
    ui->leTc->setText(_veri->tcKimlik());
    ui->spnSicilNo->setValue(_veri->sicilNo());
    /*ui->deDogumTarihi->setDate(_veri->dogumTarihi());*/
    ui->rbErkek->setChecked(_veri->cinsiyeti());
    ui->rbKadin->setChecked(_veri->cinsiyeti());
}

void GozetmenVeriGirisi::veriGuncelle()
{
    _veri->setAd(ui->leAdi->text());
    _veri->setSoyad(ui->leSoyadi->text());
    _veri->setSicilNo(ui->spnSicilNo->value());
   /* _veri->setCinsiyeti(ui->rbErkek->text());*/
   /* _veri->setCinsiyeti(ui->rbKadin->text());*/
    /*_veri->setDogumTarihi(ui->deDogumTarihi->date());*/
}
