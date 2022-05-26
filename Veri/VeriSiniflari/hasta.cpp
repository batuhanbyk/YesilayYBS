#include "hasta.h"

Hasta::Hasta(QObject *parent)
    : Insan{parent}
{

}

const Metin &Hasta::oykusu() const
{
    return _oykusu;
}

void Hasta::setOykusu(const Metin &newOykusu)
{
    if (_oykusu == newOykusu)
        return;
    _oykusu = newOykusu;
    emit oykusuChanged(_oykusu);
}

Tamsayi Hasta::psikiyatrId() const
{
    return _psikiyatrId;
}

void Hasta::setPsikiyatrId(Tamsayi newPsikiyatrId)
{
    if (_psikiyatrId == newPsikiyatrId)
        return;
    _psikiyatrId = newPsikiyatrId;
    emit psikiyatrIdChanged(_psikiyatrId);
}

Tamsayi Hasta::bagimlilikTuruTeshisId() const
{
    return _bagimlilikTuruTeshisId;
}

void Hasta::setBagimlilikTuruTeshisId(Tamsayi newBagimlilikTuruTeshisId)
{
    if (_bagimlilikTuruTeshisId == newBagimlilikTuruTeshisId)
        return;
    _bagimlilikTuruTeshisId = newBagimlilikTuruTeshisId;
    emit bagimlilikTuruTeshisIdChanged(_bagimlilikTuruTeshisId);
}
QDataStream &operator<<(QDataStream &stream, const Hasta &veri){
    stream << veri._ad;
    stream << veri._bagimlilikTuruTeshisId;
    stream << veri._oykusu;
    stream << veri._psikiyatrId;
    stream << veri._cinsiyeti;
    stream << veri._dogumTarihi;
    stream << veri._id;
    stream << veri._silindiMi;
    stream << veri._soyad;
    stream << veri._tcKimlik;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Hasta &veri){
    stream >> veri._ad;
    stream >> veri._bagimlilikTuruTeshisId;
    stream >> veri._oykusu;
    stream >> veri._psikiyatrId;
    stream >> veri._cinsiyeti;
    stream >> veri._dogumTarihi;
    stream >> veri._id;
    stream >> veri._silindiMi;
    stream >> veri._soyad;
    stream >> veri._tcKimlik;
    return stream;
}
