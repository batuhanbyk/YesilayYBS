#include "insan.h"

Insan::Insan(QObject *parent)
    : TemVerSinifi{parent}
{

}

const Metin &Insan::tcKimlik() const
{
    return _tcKimlik;
}

void Insan::setTcKimlik(const Metin &newTcKimlik)
{
    if (_tcKimlik == newTcKimlik)
        return;
    _tcKimlik = newTcKimlik;
    emit tcKimlikChanged(_tcKimlik);
}

const Metin &Insan::ad() const
{
    return _ad;
}

void Insan::setAd(const Metin &newAd)
{
    if (_ad == newAd)
        return;
    _ad = newAd;
    emit adChanged(_ad);
}

const Metin &Insan::soyad() const
{
    return _soyad;
}

void Insan::setSoyad(const Metin &newSoyad)
{
    if (_soyad == newSoyad)
        return;
    _soyad = newSoyad;
    emit soyadChanged(_soyad);
}

const Metin &Insan::dogumTarihi() const
{
    return _dogumTarihi;
}

void Insan::setDogumTarihi(const Metin &newDogumTarihi)
{
    if (_dogumTarihi == newDogumTarihi)
        return;
    _dogumTarihi = newDogumTarihi;
    emit dogumTarihiChanged(_dogumTarihi);
}

Cinsiyet Insan::cinsiyeti() const
{
    return _cinsiyeti;
}

void Insan::setCinsiyeti(Cinsiyet newCinsiyeti)
{
    if (_cinsiyeti == newCinsiyeti)
        return;
    _cinsiyeti = newCinsiyeti;
    emit cinsiyetiChanged(_cinsiyeti);
}

const Tarih &Insan::dogumTarihi1() const
{
    return _dogumTarihi1;
}

void Insan::setDogumTarihi1(const Tarih &newDogumTarihi1)
{
    if (_dogumTarihi1 == newDogumTarihi1)
        return;
    _dogumTarihi1 = newDogumTarihi1;
    emit dogumTarihi1Changed(_dogumTarihi1);
}
