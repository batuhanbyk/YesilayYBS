#include "gozetmenverigirisi.h"
#include "ui_gozetmenverigirisi.h"

GozetmenVeriGirisi::GozetmenVeriGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GozetmenVeriGirisi)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this,SIGNAL(veriKaydet()));
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
    ui->deDogumTarihi->setDate(_veri->dogumTarihi1());
    if(ui->rbErkek->isChecked()==true){
        _veri->setCinsiyeti(Erkek);
    }
    if(ui->rbKadin->isChecked()==true){
        _veri->setCinsiyeti(Kadin);
    }
}

void GozetmenVeriGirisi::veriGuncelle()
{
    _veri->setAd(ui->leAdi->text());
    _veri->setSoyad(ui->leSoyadi->text());
    _veri->setSicilNo(ui->spnSicilNo->value());
    _veri->setTcKimlik(ui->leTc->text());
    if(_veri->cinsiyeti()==Erkek){
        ui->rbErkek->setChecked(true);
    }
    if(_veri->cinsiyeti()==Kadin){
        ui->rbKadin->setChecked(true);
    }
    _veri->setDogumTarihi1(ui->deDogumTarihi->date());
}
