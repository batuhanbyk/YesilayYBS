#include "sonuc.h"

Sonuc::Sonuc(QObject *parent)
    : TemVerSinifi{parent}
{

}

bool Sonuc::basariliMi() const
{
    return _basariliMi;
}

void Sonuc::setBasariliMi(bool newBasariliMi)
{
    if (_basariliMi == newBasariliMi)
        return;
    _basariliMi = newBasariliMi;
    emit basariliMiChanged(_basariliMi);
}

const Metin &Sonuc::iyilesmeSuresi() const
{
    return _iyilesmeSuresi;
}

void Sonuc::setIyilesmeSuresi(const Metin &newIyilesmeSuresi)
{
    if (_iyilesmeSuresi == newIyilesmeSuresi)
        return;
    _iyilesmeSuresi = newIyilesmeSuresi;
    emit iyilesmeSuresiChanged(_iyilesmeSuresi);
}

const Metin &Sonuc::hastaId() const
{
    return _hastaId;
}

void Sonuc::setHastaId(const Metin &newHastaId)
{
    if (_hastaId == newHastaId)
        return;
    _hastaId = newHastaId;
    emit hastaIdChanged(_hastaId);
}
QDataStream &operator<<(QDataStream &stream, const Sonuc &veri){
    stream << veri._basariliMi;
    stream << veri._hastaId;
    stream << veri._iyilesmeSuresi;
    stream << veri._id;
    stream << veri._silindiMi;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Sonuc &veri){
    stream >> veri._basariliMi;
    stream >> veri._hastaId;
    stream >> veri._iyilesmeSuresi;
    stream >> veri._id;
    stream >> veri._silindiMi;
    return stream;
}
