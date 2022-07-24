#include "hastalisteformu.h"
#include "ui_hastalisteformu.h"
#include<QStringList>
#include<QTableWidgetItem>
#include<vector>
#include<QSize>
#include<Veri/VeriSiniflari/hasta.h>
#include<Veri/VeriDepolari/hastadeposu.h>
#include<Islemler/islemdeposu.h>
#include<Islemler/VeriSilme/hastasilmeislemi.h>
#include<Islemler/VeriGuncelleme/hastaguncellemeislemi.h>
HastaListeFormu::HastaListeFormu(HastaDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HastaListeFormu),_depo(depo)
{
    ui->setupUi(this);
    auto islem1 = IslemDeposu::v1vv().getIslem(IslemDeposu::IslemHastaGuncelle);
    auto islem2 = std::dynamic_pointer_cast<HastaGuncellemeIslemi>(islem1);
    connect(islem2.get(),&HastaGuncellemeIslemi::islemTamamlandi,ui->btnAra,&QPushButton::click);
}

HastaListeFormu::~HastaListeFormu()
{
    delete ui;
}

const HastaListesi &HastaListeFormu::liste1() const
{
    return _liste1;
}

void HastaListeFormu::setListe1(const HastaListesi &newListe1)
{
    _liste1 = newListe1;
}

const HastaListesi &HastaListeFormu::liste() const
{
    return _liste;
}

void HastaListeFormu::setListe(const HastaListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void HastaListeFormu::on_btnAra_clicked()
{
    HastaFiltrelemeFonksiyonu f;
    if(ui->rbHastaAdi->isChecked()){
        f.setAlanAdi("ad");
    }
    if(ui->rbHastaSoyadi->isChecked()){
        f.setAlanAdi("soyadi");
    }

    if(ui->rbIceren->isChecked()){
        f.setFiltre(HastaFiltrelemeFonksiyonu::FiltreIceren);
    }

    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(HastaFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }

    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(HastaFiltrelemeFonksiyonu::FiltreIleBiten);
    }
    f.setArananDeger(ui->leArama->text());
    auto liste =_depo.tumunuBul(f);
    setListe(liste);
}

void HastaListeFormu::ekranGuncelle()
{
    ui->tblHastaListesi->clear();
    ui->tblHastaListesi->setColumnCount(8);
    QStringList Basliklar;
    Basliklar <<tr("T.C.") << tr("Adi") << tr("Soyadi") << tr("Oykusu") << tr("Cinsiyeti")<< tr("Dogum Tarihi")
             <<tr("Veri Guncelle")<<tr("Veri Sil");
    ui->tblHastaListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblHastaListesi->setRowCount(_liste.size());
    for (int i=0;i<_liste.size();i++ ) {
        const auto &nesne_i=_liste[i];
        QTableWidgetItem *hucre= new QTableWidgetItem;
        hucre->setText(nesne_i->tcKimlik());
        ui->tblHastaListesi->setItem(i,0,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->ad());
        ui->tblHastaListesi->setItem(i,1,hucre);
        hucre = new QTableWidgetItem;
        hucre ->setText(nesne_i->soyad());
        ui->tblHastaListesi->setItem(i,2,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->oykusu());
        ui->tblHastaListesi->setItem(i,3,hucre);
        hucre = new QTableWidgetItem;
        if(nesne_i->cinsiyeti()==0){
            hucre->setText("Kadin");
        }
        else if(nesne_i->cinsiyeti()==1){
            hucre->setText("Erkek");
        }
        ui->tblHastaListesi->setItem(i,4,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->dogumTarihi1().toString("dd-MM-yyyy"));
        ui->tblHastaListesi->setItem(i,5,hucre);
        auto gui = ui;

        auto guncellemeButonu = new QPushButton();
        guncellemeButonu-> setText("Guncelle");
        ui->tblHastaListesi->setCellWidget(i,6,guncellemeButonu);
        /*connect(silmeButonu,&QPushButton::clicked,IslemDeposu::v1vv().getAction(IslemDeposu::IslemHastaSil),&QAction::trigger);*/

        connect(guncellemeButonu, &QPushButton::clicked,[nesne_i,gui](){
        auto islem1 = IslemDeposu::v1vv().getIslem(IslemDeposu::IslemHastaGuncelle);
        auto islem2 = std::dynamic_pointer_cast<HastaGuncellemeIslemi>(islem1);
        islem2->setVeri(nesne_i);
        islem2->qMain();
        });


        auto silmeButonu = new QPushButton();
        silmeButonu-> setText("Sil");
        ui->tblHastaListesi->setCellWidget(i,7,silmeButonu);
        /*connect(silmeButonu,&QPushButton::clicked,IslemDeposu::v1vv().getAction(IslemDeposu::IslemHastaSil),&QAction::trigger);*/

        connect(silmeButonu, &QPushButton::clicked,[nesne_i,gui](){
        auto islem1 = IslemDeposu::v1vv().getIslem(IslemDeposu::IslemHastaSil);
        auto islem2 = std::dynamic_pointer_cast<HastaSilmeIslemi>(islem1);
        islem2->setVeri(nesne_i);
        islem2->qMain();
        gui->btnAra->click();
        });
    }
}

bool HastaFiltrelemeFonksiyonu::operator()(HastaPtr data)
{
    if(_alanAdi == "tumu"){

    }

    QString deger;
    if(_alanAdi=="ad"){
         deger = data->ad();
    }
    if(_alanAdi=="soyad"){
         deger =data->soyad();
    }

    if(_filtre=FiltreIleBaslayan){
        auto sonuc= deger.toLower().startsWith(_arananDeger.toLower());
        return sonuc;
    }

    if(_filtre=FiltreIleBiten){
        auto sonuc= deger.toLower().endsWith(_arananDeger.toLower());
        return sonuc;
    }

    if(_filtre=FiltreIceren){
        auto sonuc= deger.toLower().contains(_arananDeger.toLower());
        return sonuc;
    }

    /*auto alanDegeri = data->property(_alanAdi.toStdString().c_str()).toString();*/
    return false;
}

const QString &HastaFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void HastaFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

HastaFiltrelemeFonksiyonu::FiltrelemeTuru HastaFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void HastaFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &HastaFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void HastaFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}
