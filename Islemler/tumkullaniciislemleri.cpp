#include "tumkullaniciislemleri.h"
#include<Islemler/VeriGirisi/birimgirisislemi.h>

TumKullaniciIslemleri::TumKullaniciIslemleri(QObject *parent)
    : QObject{parent}
{
    _islemler.append(std::make_shared<BirimGirisIslemi>());
}

TumKullaniciIslemleri &TumKullaniciIslemleri::v1v()
{
    static TumKullaniciIslemleri nesne;
    return nesne;
}

void TumKullaniciIslemleri::islemCalistir(int sira_no)
{
    _islemler[sira_no]->main();
}

QAction *TumKullaniciIslemleri::islem(int sira_no)
{
    return _islemler[sira_no]->islem();
}
