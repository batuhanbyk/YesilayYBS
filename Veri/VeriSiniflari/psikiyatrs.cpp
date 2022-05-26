#include "psikiyatrs.h"

Psikiyatrs::Psikiyatrs(QObject *parent)
    : Insan{parent}
{

}

const Metin &Psikiyatrs::psikiyatriAlani() const
{
    return _psikiyatriAlani;
}

void Psikiyatrs::setPsikiyatriAlani(const Metin &newPsikiyatriAlani)
{
    if (_psikiyatriAlani == newPsikiyatriAlani)
        return;
    _psikiyatriAlani = newPsikiyatriAlani;
    emit psikiyatriAlaniChanged(_psikiyatriAlani);
}

Tamsayi Psikiyatrs::sicilNo() const
{
    return _sicilNo;
}

void Psikiyatrs::setSicilNo(Tamsayi newSicilNo)
{
    if (_sicilNo == newSicilNo)
        return;
    _sicilNo = newSicilNo;
    emit sicilNoChanged(_sicilNo);
}

Tamsayi Psikiyatrs::birimId() const
{
    return _birimId;
}

void Psikiyatrs::setBirimId(Tamsayi newBirimId)
{
    if (_birimId == newBirimId)
        return;
    _birimId = newBirimId;
    emit birimIdChanged(_birimId);
}

