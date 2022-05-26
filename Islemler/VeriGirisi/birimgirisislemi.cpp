#include "birimgirisislemi.h"
#include<Veri/data.h>
#include<Formlar/VeriFormlari/birimverigirisi.h>
BirimGirisIslemi::BirimGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Yeni Birim Girisi"));
    _islem->setIcon(QIcon(":/Resimler/Birim.png"));
    connect(_islem,&QAction::triggered,this,&BirimGirisIslemi::main);

}


void BirimGirisIslemi::main()
{
    auto veri =Data::v1().birim().yeniNesne();
    BirimVeriGirisi *form=new BirimVeriGirisi();
    connect(form,&BirimVeriGirisi::veriKaydet,this,&BirimGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();

}

void BirimGirisIslemi::depoEkle()
{
    BirimVeriGirisi *frmx=dynamic_cast<BirimVeriGirisi *>(sender());
    auto veri = frmx->veri();
    Data::v1().birim().nesneEkle(veri);
        frmx->close();
}

QAction *BirimGirisIslemi::islem()
{
    return _islem;
}
