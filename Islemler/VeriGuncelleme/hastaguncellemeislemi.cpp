#include "hastaguncellemeislemi.h"

#include <Formlar/VeriFormlari/hastaverigirisi.h>
HastaGuncellemeIslemi::HastaGuncellemeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    connect(_islem,&QAction::triggered,this,&HastaGuncellemeIslemi::qMain);
}

QAction *HastaGuncellemeIslemi::islem()
{
    return _islem;
}

const HastaPtr &HastaGuncellemeIslemi::veri() const
{
    return _veri;
}

void HastaGuncellemeIslemi::setVeri(const HastaPtr &newVeri)
{
    _veri = newVeri;
}

void HastaGuncellemeIslemi::depoGuncelle()
{
    HastaVeriGirisi *frmx=dynamic_cast<HastaVeriGirisi *>(sender());
    auto veri = frmx->veri();
        frmx->close();
    emit islemTamamlandi();
}

void HastaGuncellemeIslemi::qMain()
{
    HastaVeriGirisi *form=new HastaVeriGirisi();
    connect(form,&HastaVeriGirisi::veriKaydet,this,&HastaGuncellemeIslemi::depoGuncelle);
    form->setVeri(_veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->baslikAta("Hasta Guncelle");
    form->show();

}
