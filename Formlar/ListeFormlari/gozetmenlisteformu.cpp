#include "gozetmenlisteformu.h"
#include "ui_gozetmenlisteformu.h"
#include<QStringList>
#include<QTableWidgetItem>
#include<vector>
#include<QSize>
#include<Veri/VeriSiniflari/gozetmen.h>
#include<Veri/VeriDepolari/gozetmendeposu.h>
GozetmenListeFormu::GozetmenListeFormu(GozetmenDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GozetmenListeFormu),_depo(depo)
{
    ui->setupUi(this);
}

GozetmenListeFormu::~GozetmenListeFormu()
{
    delete ui;
}

const GozetmenListesi &GozetmenListeFormu::liste() const
{
    return _liste;
}

void GozetmenListeFormu::setListe(const GozetmenListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

const GozetmenListesi &GozetmenListeFormu::liste1() const
{
    return _liste1;
}

void GozetmenListeFormu::setListe1(const GozetmenListesi &newListe1)
{
    _liste1 = newListe1;
}

void GozetmenListeFormu::on_btnAra_clicked()
{
    GozetmenFiltrelemeFonksiyonu f;
    if(ui->rbGozetmenAdi->isChecked()){
        f.setAlanAdi("ad");
    }
    if(ui->rbGozetmenSoyadi->isChecked()){
        f.setAlanAdi("soyadi");
    }
    if(ui->rbGozetmenSicilNo->isChecked()){
        f.setAlanAdi("sicilNo");
    }


    if(ui->rbIceren->isChecked()){
        f.setFiltre(GozetmenFiltrelemeFonksiyonu::FiltreIceren);
    }

    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(GozetmenFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }

    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(GozetmenFiltrelemeFonksiyonu::FiltreIleBiten);
    }
    f.setArananDeger(ui->leArama->text());
    auto liste =_depo.tumunuBul(f);
    setListe(liste);
}

void GozetmenListeFormu::ekranGuncelle()
{
    ui->tblGozetmenListesi->clear();
    ui->tblGozetmenListesi->setColumnCount(6);
    QStringList Basliklar;
    Basliklar <<tr("T.C.") << tr("Adi") << tr("Soyadi") << tr("Sicil No") << tr("Cinsiyeti")<< tr("Dogum Tarihi");
    ui->tblGozetmenListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblGozetmenListesi->setRowCount(_liste.size());
    for (int i=0;i<_liste.size();i++ ) {
        const auto &nesne_i=_liste[i];
        QTableWidgetItem *hucre= new QTableWidgetItem;
        hucre->setText(nesne_i->tcKimlik());
        ui->tblGozetmenListesi->setItem(i,0,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->ad());
        ui->tblGozetmenListesi->setItem(i,1,hucre);
        hucre = new QTableWidgetItem;
        hucre ->setText(nesne_i->soyad());
        ui->tblGozetmenListesi->setItem(i,2,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(QString::number(nesne_i->sicilNo()));
        ui->tblGozetmenListesi->setItem(i,3,hucre);
        hucre = new QTableWidgetItem;
        if(nesne_i->cinsiyeti()==1){
            hucre->setText("Kadin");
        }
        else if(nesne_i->cinsiyeti()==2){
            hucre->setText("Erkek");
        }
        ui->tblGozetmenListesi->setItem(i,4,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->dogumTarihi1().toString("dd-MM-yyyy"));
        ui->tblGozetmenListesi->setItem(i,5,hucre);
    }
}

bool GozetmenFiltrelemeFonksiyonu::operator()(GozetmenPtr data)
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
    if(_alanAdi=="sicilNo"){
         //deger=data->sicilNo();
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

const QString &GozetmenFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void GozetmenFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

GozetmenFiltrelemeFonksiyonu::FiltrelemeTuru GozetmenFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void GozetmenFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &GozetmenFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void GozetmenFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}
