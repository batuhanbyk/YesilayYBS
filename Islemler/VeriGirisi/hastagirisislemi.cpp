#include "hastagirisislemi.h"
#include<Veri/data.h>
#include<Formlar/VeriFormlari/hastaverigirisi.h>
HastaGirisIslemi::HastaGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Yeni Hasta Girisi"));
    _islem->setIcon(QIcon(":/Resimler/People.png"));
    connect(_islem,&QAction::triggered,this,&HastaGirisIslemi::main);
}

void HastaGirisIslemi::main()
{
    auto veri =Data::v1().hasta().yeniNesne();
    HastaVeriGirisi *form=new HastaVeriGirisi();
    connect(form,&HastaVeriGirisi::veriKaydet,this,&HastaGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void HastaGirisIslemi::depoEkle()
{
    HastaVeriGirisi *frmx=dynamic_cast<HastaVeriGirisi *>(sender());
    auto veri = frmx->veri();
    Data::v1().hasta().nesneEkle(veri);
        frmx->close();

}

QAction *HastaGirisIslemi::islem()
{
    return _islem;
}
