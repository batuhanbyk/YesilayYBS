#include "islemdeposu.h"
#include<Islemler/VeriGirisi/birimgirisislemi.h>
#include<Islemler/VeriListeleme/birimlisteislemi.h>
#include<Islemler/VeriGirisi/gozetmengirisislemi.h>
#include<Islemler/VeriListeleme/gozetmenlisteislemi.h>
#include<Islemler/VeriGirisi/hastagirisislemi.h>
#include<Islemler/VeriListeleme/hastalisteislemi.h>
#include<Islemler/VeriGirisi/psikiyatrgirisislemi.h>
#include<Islemler/VeriListeleme/psikiyatrlisteislemi.h>
#include<Islemler/VeriSilme/birimsilmeislemii.h>
#include<Islemler/VeriSilme/hastasilmeislemi.h>
#include<Islemler/VeriGuncelleme/hastaguncellemeislemi.h>
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

std::shared_ptr<TemelKullaniciIslemi> IslemDeposu::getIslem(IslemSirasi z)
{
    return _islemler[z];
}

IslemDeposu::IslemDeposu(QObject *parent)
    : QObject{parent}
{
    _islemler.append(std::make_shared<BirimGirisIslemi>());
    _islemler.append(std::make_shared<BirimListeIslemi>());
    _islemler.append(std::make_shared<GozetmenGirisIslemi>());
    _islemler.append(std::make_shared<GozetmenListeIslemi>());
    _islemler.append(std::make_shared<HastaGirisIslemi>());
    _islemler.append(std::make_shared<HastaListeIslemi>());
    _islemler.append(std::make_shared<PsikiyatrGirisIslemi>());
    _islemler.append(std::make_shared<PsikiyatrListeIslemi>());
    _islemler.append(std::make_shared<BirimSilmeIslemii>());
    _islemler.append(std::make_shared<HastaSilmeIslemi>());
    _islemler.append(std::make_shared<HastaGuncellemeIslemi>());
}
