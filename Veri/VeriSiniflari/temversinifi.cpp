#include "temversinifi.h"

TemVerSinifi::TemVerSinifi(QObject *parent)
    : QObject{parent}
{

}

Tamsayi TemVerSinifi::id() const
{
    return _id;
}

void TemVerSinifi::setId(Tamsayi newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged(_id);
}

bool TemVerSinifi::silindiMi() const
{
    return _silindiMi;
}

void TemVerSinifi::setSilindiMi(bool newSilindiMi)
{
    if (_silindiMi == newSilindiMi)
        return;
    _silindiMi = newSilindiMi;
    emit silindiMiChanged(_silindiMi);
}
