#include "ayarlar.h"
#include <QDir>
#include<QStandardPaths>
#include<QFile>
#include<QDataStream>

Ayarlar &Ayarlar::ayar()
{
    static Ayarlar ayr;
    return ayr;
}

Ayarlar::~Ayarlar()
{
    auto klasor = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    QDir a(klasor);
    if(!a.exists()){
        a.mkpath(klasor);
    }
    QFile dosya(klasor + "/ayarlar.cfg");
    if(dosya.open(QIODevice::WriteOnly)){
        QDataStream stream(&dosya);
        stream << _ocakId;
    }
}

Ayarlar::Ayarlar(QObject *parent)
    : QObject{parent}, _ocakId{-1}
{
    auto klasor = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    QDir a(klasor);
    if(!a.exists()){
        a.mkpath(klasor);
    }
    QFile dosya(klasor + "/ayarlar.cfg");
    if(dosya.open(QIODevice::ReadOnly)){
        QDataStream stream(&dosya);
        stream >> _ocakId;
    }
}

Tamsayi Ayarlar::ocakId() const
{
    return _ocakId;
}

void Ayarlar::setOcakId(Tamsayi newOcakId)
{
    if (_ocakId == newOcakId)
        return;
    _ocakId = newOcakId;
    emit ocakIdChanged(_ocakId);
}
