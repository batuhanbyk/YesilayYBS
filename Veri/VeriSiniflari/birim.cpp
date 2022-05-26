#include "birim.h"

Birim::Birim(QObject *parent)
    : TemVerSinifi{parent}
{

}

const Metin &Birim::birimAdi() const
{
    return _birimAdi;
}

void Birim::setBirimAdi(const Metin &newBirimAdi)
{
    if (_birimAdi == newBirimAdi)
        return;
    _birimAdi = newBirimAdi;
    emit birimAdiChanged(_birimAdi);
}

const Metin &Birim::birimKodu() const
{
    return _birimKodu;
}

void Birim::setBirimKodu(const Metin &newBirimKodu)
{
    if (_birimKodu == newBirimKodu)
        return;
    _birimKodu = newBirimKodu;
    emit birimKoduChanged(_birimKodu);
}

const Metin &Birim::birimIletisim() const
{
    return _birimIletisim;
}

void Birim::setBirimIletisim(const Metin &newBirimIletisim)
{
    if (_birimIletisim == newBirimIletisim)
        return;
    _birimIletisim = newBirimIletisim;
    emit birimIletisimChanged(_birimIletisim);
}

const Metin &Birim::birimAdresi() const
{
    return _birimAdresi;
}

void Birim::setBirimAdresi(const Metin &newBirimAdresi)
{
    if (_birimAdresi == newBirimAdresi)
        return;
    _birimAdresi = newBirimAdresi;
    emit birimAdresiChanged(_birimAdresi);
}
QDataStream &operator<<(QDataStream &stream, const Birim &veri){
   stream << veri._birimAdi;
   stream << veri._birimAdresi;
   stream << veri._birimIletisim;
   stream << veri._birimKodu;
   stream << veri._id;
   stream << veri._silindiMi;
   return stream;

}
QDataStream &operator>>(QDataStream &stream, Birim &veri){
    stream >> veri._birimAdi;
    stream >> veri._birimAdresi;
    stream >> veri._birimIletisim;
    stream >> veri._birimKodu;
    stream >> veri._id;
    stream >> veri._silindiMi;
    return stream;
}
