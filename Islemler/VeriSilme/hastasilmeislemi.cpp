#include "hastasilmeislemi.h"
#include<QMessageBox>
#include<Veri/VeriSiniflari/hasta.h>
#include <Veri/data.h>
HastaSilmeIslemi::HastaSilmeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    connect(_islem,&QAction::triggered,this,&HastaSilmeIslemi::main);

}

QAction *HastaSilmeIslemi::islem()
{
    return _islem;
}

const HastaPtr &HastaSilmeIslemi::veri() const
{
    return _veri;
}

void HastaSilmeIslemi::setVeri(const HastaPtr &newVeri)
{
    _veri = newVeri;
}

void HastaSilmeIslemi::qMain()
{
    auto cevap = QMessageBox::question(nullptr,tr("Hasta Silme Islemi Onayi"),tr("%1 isimli hastayi silmek istediginize emin misiniz?").arg(_veri->ad()));
    if(cevap==QMessageBox::Yes){
        Data::v1().hasta().nesneSil(_veri);
    }
}
