#include "ziyaret.h"

Ziyaret::Ziyaret(QObject *parent)
    : TemVerSinifi{parent}
{

}

const Metin &Ziyaret::sikayeti() const
{
    return _sikayeti;
}

void Ziyaret::setSikayeti(const Metin &newSikayeti)
{
    if (_sikayeti == newSikayeti)
        return;
    _sikayeti = newSikayeti;
    emit sikayetiChanged(_sikayeti);
}

const Tarih &Ziyaret::gelisTarihi() const
{
    return _gelisTarihi;
}

void Ziyaret::setGelisTarihi(const Tarih &newGelisTarihi)
{
    if (_gelisTarihi == newGelisTarihi)
        return;
    _gelisTarihi = newGelisTarihi;
    emit gelisTarihiChanged(_gelisTarihi);
}

Tamsayi Ziyaret::hastaId() const
{
    return _hastaId;
}

void Ziyaret::setHastaId(Tamsayi newHastaId)
{
    if (_hastaId == newHastaId)
        return;
    _hastaId = newHastaId;
    emit hastaIdChanged(_hastaId);
}

Tamsayi Ziyaret::gozetmenId() const
{
    return _gozetmenId;
}

void Ziyaret::setGozetmenId(Tamsayi newGozetmenId)
{
    if (_gozetmenId == newGozetmenId)
        return;
    _gozetmenId = newGozetmenId;
    emit gozetmenIdChanged(_gozetmenId);
}

Tamsayi Ziyaret::psikiyatrId() const
{
    return _psikiyatrId;
}

void Ziyaret::setPsikiyatrId(Tamsayi newPsikiyatrId)
{
    if (_psikiyatrId == newPsikiyatrId)
        return;
    _psikiyatrId = newPsikiyatrId;
    emit psikiyatrIdChanged(_psikiyatrId);
}

Tamsayi Ziyaret::tedaviYontemiId() const
{
    return _tedaviYontemiId;
}

void Ziyaret::setTedaviYontemiId(Tamsayi newTedaviYontemiId)
{
    if (_tedaviYontemiId == newTedaviYontemiId)
        return;
    _tedaviYontemiId = newTedaviYontemiId;
    emit tedaviYontemiIdChanged(_tedaviYontemiId);
}

Tamsayi Ziyaret::bagimlilikTuruTeshisId() const
{
    return _bagimlilikTuruTeshisId;
}

void Ziyaret::setBagimlilikTuruTeshisId(Tamsayi newBagimlilikTuruTeshisId)
{
    if (_bagimlilikTuruTeshisId == newBagimlilikTuruTeshisId)
        return;
    _bagimlilikTuruTeshisId = newBagimlilikTuruTeshisId;
    emit bagimlilikTuruTeshisIdChanged(_bagimlilikTuruTeshisId);
}

Tamsayi Ziyaret::birimId() const
{
    return _birimId;
}

void Ziyaret::setBirimId(Tamsayi newBirimId)
{
    if (_birimId == newBirimId)
        return;
    _birimId = newBirimId;
    emit birimIdChanged(_birimId);
}
QDataStream &operator<<(QDataStream &stream, const Ziyaret &veri){
    stream << veri._bagimlilikTuruTeshisId;
    stream << veri._birimId;
    stream << veri._gelisTarihi;
    stream << veri._gozetmenId;
    stream << veri._hastaId;
    stream << veri._psikiyatrId;
    stream << veri._sikayeti;
    stream << veri._tedaviYontemiId;
    stream << veri._id;
    stream << veri._silindiMi;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Ziyaret &veri){
    stream >> veri._bagimlilikTuruTeshisId;
    stream >> veri._birimId;
    stream >> veri._gelisTarihi;
    stream >> veri._gozetmenId;
    stream >> veri._hastaId;
    stream >> veri._psikiyatrId;
    stream >> veri._sikayeti;
    stream >> veri._tedaviYontemiId;
    stream >> veri._id;
    stream >> veri._silindiMi;
    return stream;
}
