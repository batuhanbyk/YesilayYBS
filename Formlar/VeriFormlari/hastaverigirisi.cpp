#include "hastaverigirisi.h"
#include "ui_hastaverigirisi.h"

HastaVeriGirisi::HastaVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HastaVeriGirisi)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this,SIGNAL(veriKaydet()));
}

HastaVeriGirisi::~HastaVeriGirisi()
{
    delete ui;
}


void HastaVeriGirisi::ekranGuncelle()
{
    ui->leAdi->setText(_veri->ad());
    ui->leSoyadi->setText(_veri->soyad());
    ui->leTc->setText(_veri ->tcKimlik());
    ui->teOykusu->setText(_veri->oykusu());
    if(ui->rbErkek->isChecked()==true){
        _veri->setCinsiyeti(Erkek);
    }
    if(ui->rbKadin->isChecked()==true){
        _veri->setCinsiyeti(Kadin);
    }
    ui->deDogumTarihi->setDate(_veri->dogumTarihi1());


}

void HastaVeriGirisi::veriGuncelle()
{
    _veri->setTcKimlik(ui->leTc->text());
    _veri->setAd(ui->leAdi->text());
    _veri->setSoyad(ui->leSoyadi->text());
    _veri->setOykusu(ui->teOykusu->toPlainText());

    if(_veri->cinsiyeti()==Erkek){
        ui->rbErkek->setChecked(true);
    }
    if(_veri->cinsiyeti()==Kadin){
        ui->rbKadin->setChecked(true);
    }
    _veri->setDogumTarihi1(ui->deDogumTarihi->date());
}

void HastaVeriGirisi::baslikAta(QString baslik)
{
    ui->lblBaslik->setText(baslik);
}
