#include "psikiyatrlisteformu.h"
#include "ui_psikiyatrlisteformu.h"
#include<QStringList>
#include<QTableWidgetItem>
#include<vector>
#include<QSize>
#include<Veri/VeriSiniflari/psikiyatrist.h>
#include<Veri/VeriDepolari/psikiyatristdeposu.h>
PsikiyatrListeFormu::PsikiyatrListeFormu(PsikiyatristDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PsikiyatrListeFormu),_depo(depo)
{
    ui->setupUi(this);
}

PsikiyatrListeFormu::~PsikiyatrListeFormu()
{
    delete ui;
}

const PsikiyatrListesi &PsikiyatrListeFormu::liste() const
{
    return _liste;
}

void PsikiyatrListeFormu::setListe(const PsikiyatrListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

const PsikiyatrListesi &PsikiyatrListeFormu::liste1() const
{
    return _liste1;
}

void PsikiyatrListeFormu::setListe1(const PsikiyatrListesi &newListe1)
{
    _liste1 = newListe1;
}

void PsikiyatrListeFormu::on_btnAra_clicked()
{
    PsikiyatrFiltrelemeFonksiyonu f;
    if(ui->rbPsikiyatrAdi->isChecked()){
        f.setAlanAdi("ad");
    }
    if(ui->rbPsikiyatrSoyadi->isChecked()){
        f.setAlanAdi("soyadi");
    }

    if(ui->rbIceren->isChecked()){
        f.setFiltre(PsikiyatrFiltrelemeFonksiyonu::FiltreIceren);
    }

    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(PsikiyatrFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }

    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(PsikiyatrFiltrelemeFonksiyonu::FiltreIleBiten);
    }
    f.setArananDeger(ui->leArama->text());
    auto liste =_depo.tumunuBul(f);
    setListe(liste);
}

void PsikiyatrListeFormu::ekranGuncelle()
{
    ui->tblPsikiyatrListesi->clear();
    ui->tblPsikiyatrListesi->setColumnCount(7);
    QStringList Basliklar;
    Basliklar <<tr("T.C.") << tr("Adi") << tr("Soyadi") << tr("Alani") << tr("Cinsiyeti")<< tr("Dogum Tarihi")<<tr("Sicil No");
    ui->tblPsikiyatrListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblPsikiyatrListesi->setRowCount(_liste.size());
    for (int i=0;i<_liste.size();i++ ) {
        const auto &nesne_i=_liste[i];
        QTableWidgetItem *hucre= new QTableWidgetItem;
        hucre->setText(nesne_i->tcKimlik());
        ui->tblPsikiyatrListesi->setItem(i,0,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->ad());
        ui->tblPsikiyatrListesi->setItem(i,1,hucre);
        hucre = new QTableWidgetItem;
        hucre ->setText(nesne_i->soyad());
        ui->tblPsikiyatrListesi->setItem(i,2,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->psikiyatriAlani());
        ui->tblPsikiyatrListesi->setItem(i,3,hucre);
        hucre = new QTableWidgetItem;
        if(nesne_i->cinsiyeti()==1){
            hucre->setText("Kadin");
        }
        else if(nesne_i->cinsiyeti()==2){
            hucre->setText("Erkek");
        }
        ui->tblPsikiyatrListesi->setItem(i,4,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->dogumTarihi1().toString("dd-MM-yyyy"));
        ui->tblPsikiyatrListesi->setItem(i,5,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(QString::number(nesne_i->sicilNo()));
        ui->tblPsikiyatrListesi->setItem(i,6,hucre);
    }
}

bool PsikiyatrFiltrelemeFonksiyonu::operator()(PsikiyatrPtr data)
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

const QString &PsikiyatrFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void PsikiyatrFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

PsikiyatrFiltrelemeFonksiyonu::FiltrelemeTuru PsikiyatrFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void PsikiyatrFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &PsikiyatrFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void PsikiyatrFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}
