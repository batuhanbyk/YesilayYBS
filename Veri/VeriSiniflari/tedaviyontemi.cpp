#include "tedaviyontemi.h"

TedaviYontemi::TedaviYontemi(QObject *parent)
    : TemVerSinifi{parent}
{

}

const Metin &TedaviYontemi::tibbi() const
{
    return _tibbi;
}

void TedaviYontemi::setTibbi(const Metin &newTibbi)
{
    if (_tibbi == newTibbi)
        return;
    _tibbi = newTibbi;
    emit tibbiChanged(_tibbi);
}

const Metin &TedaviYontemi::psikolojik() const
{
    return _psikolojik;
}

void TedaviYontemi::setPsikolojik(const Metin &newPsikolojik)
{
    if (_psikolojik == newPsikolojik)
        return;
    _psikolojik = newPsikolojik;
    emit psikolojikChanged(_psikolojik);
}

QDataStream &operator<<(QDataStream &stream, const TedaviYontemi &veri){
    stream << veri._id;
    stream << veri._psikolojik;
    stream << veri._tibbi;
    stream << veri._silindiMi;
    return stream;

}
QDataStream &operator>>(QDataStream &stream, TedaviYontemi &veri){
    stream >> veri._id;
    stream >> veri._psikolojik;
    stream >> veri._tibbi;
    stream >> veri._silindiMi;
    return stream;
}
