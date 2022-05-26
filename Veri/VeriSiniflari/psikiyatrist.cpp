#include "psikiyatrist.h"

Psikiyatrist::Psikiyatrist(QObject *parent)
    : Insan{parent}
{

}

const Metin &Psikiyatrist::psikiyatriAlani() const
{
    return _psikiyatriAlani;
}

void Psikiyatrist::setPsikiyatriAlani(const Metin &newPsikiyatriAlani)
{
    if (_psikiyatriAlani == newPsikiyatriAlani)
        return;
    _psikiyatriAlani = newPsikiyatriAlani;
    emit psikiyatriAlaniChanged(_psikiyatriAlani);
}

Tamsayi Psikiyatrist::sicilNo() const
{
    return _sicilNo;
}

void Psikiyatrist::setSicilNo(Tamsayi newSicilNo)
{
    if (_sicilNo == newSicilNo)
        return;
    _sicilNo = newSicilNo;
    emit sicilNoChanged(_sicilNo);
}

Tamsayi Psikiyatrist::birimId() const
{
    return _birimId;
}

void Psikiyatrist::setBirimId(Tamsayi newBirimId)
{
    if (_birimId == newBirimId)
        return;
    _birimId = newBirimId;
    emit birimIdChanged(_birimId);
}
QDataStream &operator<<(QDataStream &stream, const Psikiyatrist &veri){
    stream << veri._ad;
    stream << veri._birimId;
    stream << veri._psikiyatriAlani;
    stream << veri._sicilNo;
    stream << veri._cinsiyeti;
    stream << veri._dogumTarihi;
    stream << veri._id;
    stream << veri._silindiMi;
    stream << veri._soyad;
    stream << veri._tcKimlik;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Psikiyatrist &veri){
    stream >> veri._ad;
    stream >> veri._birimId;
    stream >> veri._psikiyatriAlani;
    stream >> veri._sicilNo;
    stream >> veri._cinsiyeti;
    stream >> veri._dogumTarihi;
    stream >> veri._id;
    stream >> veri._silindiMi;
    stream >> veri._soyad;
    stream >> veri._tcKimlik;
    return stream;
}
