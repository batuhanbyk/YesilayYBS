#include "soyesilay.h"
#include "ui_soyesilay.h"
#include<Islemler/islemdeposu.h>

SOYesilay::SOYesilay(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SOYesilay)
{
    ui->setupUi(this);
    ui->menuVeri_Giris_Islemi->addAction(IslemDeposu::v1vv().getAction(IslemDeposu::IslemBirimGiris));
    ui->menuVeri_Giris_Islemi->addAction(IslemDeposu::v1vv().getAction(IslemDeposu::IslemSaglikOcagiListe));
    ui->toolBarVeriGiris->addAction(IslemDeposu::v1vv().getAction(IslemDeposu::IslemBirimGiris));
    /*addActionlar butonlardanda calisabiliyor istenilen yerden kullanilir*/
}

SOYesilay::~SOYesilay()
{
    delete ui;
}




