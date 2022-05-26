#include "gozetmen.h"

Gozetmen::Gozetmen(QObject *parent)
    : Insan{parent}
{

}

Tamsayi Gozetmen::sicilNo() const
{
    return _sicilNo;
}

void Gozetmen::setSicilNo(Tamsayi newSicilNo)
{
    if (_sicilNo == newSicilNo)
        return;
    _sicilNo = newSicilNo;
    emit sicilNoChanged(_sicilNo);
}

Tamsayi Gozetmen::birimId() const
{
    return _birimId;
}

void Gozetmen::setBirimId(Tamsayi newBirimId)
{
    if (_birimId == newBirimId)
        return;
    _birimId = newBirimId;
    emit birimIdChanged(_birimId);
}

QDataStream &operator<<(QDataStream &stream, const Gozetmen &veri){
    stream << veri._ad;
    stream << veri._birimId;
    stream << veri._sicilNo;
    stream << veri._cinsiyeti;
    stream << veri._dogumTarihi;
    stream << veri._soyad;
    stream << veri._tcKimlik;
    stream << veri._id;
    stream << veri._silindiMi;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Gozetmen &veri){
    stream >> veri._ad;
    stream >> veri._birimId;
    stream >> veri._sicilNo;
    stream >> veri._cinsiyeti;
    stream >> veri._dogumTarihi;
    stream >> veri._soyad;
    stream >> veri._tcKimlik;
    stream >> veri._id;
    stream >> veri._silindiMi;
    return stream;
}
