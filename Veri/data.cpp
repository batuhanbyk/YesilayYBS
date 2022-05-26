#include "data.h"
#include<QStandardPaths>
#include<QDir>
#include<QFile>
#include<QDataStream>
#include<QDebug>

void Data::kaydet()
{
    QFile dosya(dosyaYolu());
    if(dosya.open(QIODevice::WriteOnly)){
        QDataStream out(&dosya);
        out << *this;
        dosya.close();
    }
}

void Data::yukle()
{
    QFile dosya(dosyaYolu());
    if(dosya.open(QIODevice::ReadOnly)){
        QDataStream in(&dosya);
        in >> *this;
        dosya.close();
    }
}

Data::~Data()
{
    qDebug() << "Data Sonlandiriliyori veri kaydediliyor...";
    kaydet();
}

Data::Data(QObject *parent)
    : QObject{parent}
{
  qDebug() << "Data Ilklendiriliyor, veri yukleniyor...";
  yukle();
}

QString Data::dosyaYolu()
{
    auto klasor = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QDir a(klasor);
    if(!a.exists()){
         a.mkpath(klasor);
    }
    qDebug() << klasor + "/veri.dat";
    return klasor + "/veri.dat";
}

QDataStream &operator<<(QDataStream &stream, const Data &veri){
    stream << veri._birim;
    stream << veri._psikiyatrist;
    stream << veri._bagimlilikTuruTeshis;
    stream << veri._gozetmen;
    stream << veri._tedaviYontemi;
    stream << veri._sonuc;
    stream << veri._hasta;
    stream << veri._ziyaret;
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Data &veri){
    stream >> veri._birim;
    stream >> veri._psikiyatrist;
    stream >> veri._bagimlilikTuruTeshis;
    stream >> veri._gozetmen;
    stream >> veri._tedaviYontemi;
    stream >> veri._sonuc;
    stream >> veri._hasta;
    stream >> veri._ziyaret;
    return stream;
}
