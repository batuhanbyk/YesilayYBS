#include "islemdeposu.h"
#include<Islemler/VeriGirisi/birimgirisislemi.h>
#include<Islemler/VeriListeleme/birimlisteislemi.h>
IslemDeposu &IslemDeposu::v1vv()
{
    static IslemDeposu v1v1;
    return v1v1;
}

QAction *IslemDeposu::getAction(IslemSirasi x)
{
    return _islemler[x]->islem();
}

void IslemDeposu::calistir(IslemSirasi y)
{
    _islemler[y]->main();
}

IslemDeposu::IslemDeposu(QObject *parent)
    : QObject{parent}
{
    _islemler.append(std::make_shared<BirimGirisIslemi>());
    _islemler.append(std::make_shared<BirimListeIslemi>());
}
