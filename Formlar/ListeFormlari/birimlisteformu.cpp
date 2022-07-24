#include "birimlisteformu.h"
#include "ui_birimlisteformu.h"
#include<QStringList>
#include<QTableWidgetItem>
#include<vector>
#include<QSize>
#include<Veri/VeriSiniflari/birim.h>
#include<Veri/VeriDepolari/birimdeposu.h>
#include<Islemler/islemdeposu.h>
#include<Islemler/VeriSilme/birimsilmeislemii.h>

BirimListeFormu::BirimListeFormu(BirimDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BirimListeFormu),_depo(depo)
{
    ui->setupUi(this);
}

BirimListeFormu::~BirimListeFormu()
{
    delete ui;
}

const BirimListesi &BirimListeFormu::liste() const
{
    return _liste;
}

void BirimListeFormu::setListe(const BirimListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void BirimListeFormu::ekranGuncelle()
{
    ui->tblBirimListesi->clear();
    ui->tblBirimListesi->setColumnCount(5);
    QStringList Basliklar;
    Basliklar << tr("Birim Adi") << tr("Birim Kodu") << tr("Birim Adresi") << tr("Telefon Numarasi")<<  tr("Veri Sil");
    ui->tblBirimListesi->setHorizontalHeaderLabels(Basliklar);
    ui->tblBirimListesi->setRowCount(_liste.size());
    for (int i=0;i<_liste.size();i++ ) {
        const auto &nesne_i=_liste[i];
        QTableWidgetItem *hucre= new QTableWidgetItem;
        hucre->setText(nesne_i->birimAdi());
        ui->tblBirimListesi->setItem(i,0,hucre);
        hucre = new QTableWidgetItem;
        hucre ->setText(nesne_i->birimKodu());
        ui->tblBirimListesi->setItem(i,1,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->birimAdresi());
        ui->tblBirimListesi->setItem(i,2,hucre);
        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->birimIletisim());
        ui->tblBirimListesi->setItem(i,3,hucre);

        auto silmeButonu = new QPushButton();
        silmeButonu->setText("Sil");
        /*connect(silmeButonu, &QPushButton::clicked,IslemDeposu::v1vv().getAction(IslemDeposu::IslemSaglikOcagiSil),&QAction::trigger);*/
        connect(silmeButonu,&QPushButton::clicked,[nesne_i](){
            auto islem1 = IslemDeposu::v1vv().getIslem(IslemDeposu::IslemSaglikOcagiSil);
            auto islem2 = std::dynamic_pointer_cast<BirimSilmeIslemii>(islem1); //Temel veri islemini BirimSil islemine donusturur.
            //std::reinterpret_pointer_cast(); //Tum temel veri islemindeki pointerlar cocuk siniflara cast edilebilirler(casting).
            islem2->setVeri(nesne_i);
            islem2-> main();
        });

        ui->tblBirimListesi->setCellWidget(i, 4, silmeButonu);
        //trigger sinyalin adi triggered slotun
    }
}

const BirimListesi &BirimListeFormu::liste1() const
{
    return _liste1;
}

void BirimListeFormu::setListe1(const BirimListesi &newListe1)
{
    _liste1 = newListe1;
}

const QString &BirimFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void BirimFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

BirimFiltrelemeFonksiyonu::FiltrelemeTuru BirimFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void BirimFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &BirimFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void BirimFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

bool BirimFiltrelemeFonksiyonu::operator()(BirimPtr data)
{
    if(_alanAdi == "tumu"){

    }

    QString deger;
    if(_alanAdi=="birimKodu"){
         deger = data->birimKodu();
    }
    if(_alanAdi=="birimAdi"){
         deger =data->birimAdi();
    }
    if(_alanAdi=="birimAdresi"){
         deger= data->birimAdresi();
    }
    if(_alanAdi=="birimIletisim"){
         deger = data->birimIletisim();
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

void BirimListeFormu::on_btnAra_clicked()
{
    BirimFiltrelemeFonksiyonu f;
    if(ui->rbBirimAdi->isChecked()){
        f.setAlanAdi("birimAdi");
    }
    if(ui->rbBirimKodu->isChecked()){
        f.setAlanAdi("birimKodu");
    }
    if(ui->rbBirimAdresi->isChecked()){
        f.setAlanAdi("birimAdresi");
    }


    if(ui->rbIceren->isChecked()){
        f.setFiltre(BirimFiltrelemeFonksiyonu::FiltreIceren);
    }

    if(ui->rbIleBaslayan->isChecked()){
        f.setFiltre(BirimFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }

    if(ui->rbIleBiten->isChecked()){
        f.setFiltre(BirimFiltrelemeFonksiyonu::FiltreIleBiten);
    }
    f.setArananDeger(ui->leArama->text());
    auto liste =_depo.tumunuBul(f);
    setListe(liste);
}

