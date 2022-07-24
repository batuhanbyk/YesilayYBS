#include "psikiyatrgirisislemi.h"
#include<Veri/data.h>
#include<Formlar/VeriFormlari/psikiyatrverigirisi.h>
PsikiyatrGirisIslemi::PsikiyatrGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Yeni Psikiyatr Girisi"));
    _islem->setIcon(QIcon(":/Resimler/People.png"));
    connect(_islem,&QAction::triggered,this,&PsikiyatrGirisIslemi::main);
}
void PsikiyatrGirisIslemi::main()
{
    auto veri =Data::v1().psikiyatrist().yeniNesne();
    PsikiyatrVeriGirisi *form=new PsikiyatrVeriGirisi();
    connect(form,&PsikiyatrVeriGirisi::veriKaydet,this,&PsikiyatrGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void PsikiyatrGirisIslemi::depoEkle()
{
    PsikiyatrVeriGirisi *frmx=dynamic_cast<PsikiyatrVeriGirisi *>(sender());
    auto veri = frmx->veri();
    Data::v1().psikiyatrist().nesneEkle(veri);
        frmx->close();
}

QAction *PsikiyatrGirisIslemi::islem()
{
    return _islem;
}
