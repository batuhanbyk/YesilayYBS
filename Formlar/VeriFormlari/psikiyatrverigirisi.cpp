#include "psikiyatrverigirisi.h"
#include "ui_psikiyatrverigirisi.h"

PsikiyatrVeriGirisi::PsikiyatrVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PsikiyatrVeriGirisi)
{
    ui->setupUi(this);
    connect(ui->btnKaydet_2,SIGNAL(clicked()),this,SIGNAL(veriKaydet()));
}

PsikiyatrVeriGirisi::~PsikiyatrVeriGirisi()
{
    delete ui;
}


void PsikiyatrVeriGirisi::ekranGuncelle()
{
    ui->leAdi_2->setText(_veri->ad());
    ui->leSoyadi_2->setText(_veri->soyad());
    ui->leTc_2->setText(_veri ->tcKimlik());
    if(ui->rbErkek_2->isChecked()==true){
        _veri->setCinsiyeti(Erkek);
    }
    if(ui->rbKadin_2->isChecked()==true){
        _veri->setCinsiyeti(Kadin);
    }
    ui->deDogumTarihi_2->setDate(_veri->dogumTarihi1());
    ui->leAlani->setText(_veri->psikiyatriAlani());
    ui->spnSicilNo->setValue(_veri->sicilNo());
}

void PsikiyatrVeriGirisi::veriGuncelle()
{
    _veri->setTcKimlik(ui->leTc_2->text());
    _veri->setAd(ui->leAdi_2->text());
    _veri->setSoyad(ui->leSoyadi_2->text());
    _veri->setPsikiyatriAlani(ui->leAlani->text());

    if(_veri->cinsiyeti()==Erkek){
        ui->rbErkek_2->setChecked(true);
    }
    if(_veri->cinsiyeti()==Kadin){
        ui->rbKadin_2->setChecked(true);
    }
    _veri->setDogumTarihi1(ui->deDogumTarihi_2->date());
    _veri->setSicilNo(ui->spnSicilNo->value());
}
