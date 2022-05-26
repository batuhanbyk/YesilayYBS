#ifndef DATA_H
#define DATA_H

#include <QObject>
#include<QDataStream>
#include<Veri/VeriDepolari/bagimlilikturuteshisdepo.h>
#include<Veri/VeriDepolari/birimdeposu.h>
#include<Veri/VeriDepolari/gozetmendeposu.h>
#include<Veri/VeriDepolari/hastadeposu.h>
#include<Veri/VeriDepolari/psikiyatristdeposu.h>
#include<Veri/VeriDepolari/sonucdeposu.h>
#include<Veri/VeriDepolari/tedaviyontemideposu.h>
#include<Veri/VeriDepolari/ziyaretdeposu.h>

class Data : public QObject
{
    Q_OBJECT
public:
    BagimlilikTuruTeshisDepo &bagimlilikturuteshis(){return  _bagimlilikTuruTeshis;}
    BirimDeposu &birim() {return _birim;}
    GozetmenDeposu &gozetmen() {return  _gozetmen;}
    HastaDeposu &hasta() {return  _hasta;}
    PsikiyatristDeposu &psikiyatrist() {return _psikiyatrist;}
    SonucDeposu &sonuc() {return _sonuc;}
    TedaviYontemiDeposu &tedaviyontemi(){return  _tedaviYontemi;}
    ZiyaretDeposu &ziyaret(){return _ziyaret;}

    void kaydet();
    void yukle();
     ~Data();
    static Data &v1(){
        static Data v11;
        return v11;
    }

signals:
private:
    explicit Data(QObject *parent = nullptr);
    BagimlilikTuruTeshisDepo _bagimlilikTuruTeshis;
    BirimDeposu _birim;
    GozetmenDeposu _gozetmen;
    HastaDeposu _hasta;
    PsikiyatristDeposu _psikiyatrist;
    SonucDeposu _sonuc;
    TedaviYontemiDeposu _tedaviYontemi;
    ZiyaretDeposu _ziyaret;

    QString dosyaYolu();

    friend QDataStream &operator<<(QDataStream &stream, const Data &veri);
    friend QDataStream &operator>>(QDataStream &stream, Data &veri);
};

QDataStream &operator<<(QDataStream &stream, const Data &veri);
QDataStream &operator>>(QDataStream &stream, Data &veri);

/*void deneme(){
    auto sag=Data::v1().birim().yeniNesne();
    sag->setBirimAdi("YESILAY");
    Data::v1().birim().nesneEkle(sag);
}*/

#endif // DATA_H
