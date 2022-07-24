#include "birimsilmeislemii.h"

#include<Veri/data.h>
#include<QMessageBox>
#include<Veri/VeriSiniflari/birim.h>

BirimSilmeIslemii::BirimSilmeIslemii(QObject *parent):QObject(parent)
{
    _islem = new QAction();
    connect(_islem, &QAction::triggered, this, &BirimSilmeIslemii::main);
}

QAction *BirimSilmeIslemii::islem()
{
    return _islem;
}

const BirimPtr &BirimSilmeIslemii::veri() const
{
    return _veri;
}

void BirimSilmeIslemii::setVeri(const BirimPtr &newVeri)
{
    _veri = newVeri;
}

void BirimSilmeIslemii::setIslem(QAction *newIslem)
{
    _islem = newIslem;
}

void BirimSilmeIslemii::main()
{
    auto cevap= QMessageBox::question(nullptr,tr("Birim Silme Onayi"),tr("%1 isimli Birimi Silmek İstediginden Emin Misin?").arg(_veri->birimAdi()));

    if(cevap==QMessageBox::Yes){
        Data::v1().birim().nesneSil(_veri);
    }
}
