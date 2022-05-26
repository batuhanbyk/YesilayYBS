#include "bagimlilikturuteshis.h"

BagimlilikTuruTeshis::BagimlilikTuruTeshis(QObject *parent)
    : TemVerSinifi{parent}
{

}

const Metin &BagimlilikTuruTeshis::bagimlilikTuru() const
{
    return _bagimlilikTuru;
}

void BagimlilikTuruTeshis::setBagimlilikTuru(const Metin &newBagimlilikTuru)
{
    if (_bagimlilikTuru == newBagimlilikTuru)
        return;
    _bagimlilikTuru = newBagimlilikTuru;
    emit bagimlilikTuruChanged(_bagimlilikTuru);
}

const Metin &BagimlilikTuruTeshis::bagimlilikKademesi() const
{
    return _bagimlilikKademesi;
}

void BagimlilikTuruTeshis::setBagimlilikKademesi(const Metin &newBagimlilikKademesi)
{
    if (_bagimlilikKademesi == newBagimlilikKademesi)
        return;
    _bagimlilikKademesi = newBagimlilikKademesi;
    emit bagimlilikKademesiChanged(_bagimlilikKademesi);
}

Tamsayi BagimlilikTuruTeshis::hastaId() const
{
    return _hastaId;
}

void BagimlilikTuruTeshis::setHastaId(Tamsayi newHastaId)
{
    if (_hastaId == newHastaId)
        return;
    _hastaId = newHastaId;
    emit hastaIdChanged(_hastaId);
}

QDataStream &operator<<(QDataStream &stream, const BagimlilikTuruTeshis &veri){
    stream << veri._hastaId;
    stream << veri._bagimlilikTuru;
    stream << veri._bagimlilikKademesi;
    stream << veri._id;
    stream << veri._silindiMi;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, BagimlilikTuruTeshis &veri){
    stream >> veri._hastaId;
    stream >> veri._bagimlilikTuru;
    stream >> veri._bagimlilikKademesi;
    stream >> veri._id;
    stream >> veri._silindiMi;
    return stream;
}
