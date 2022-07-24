#include "gozetmengirisislemi.h"
#include<Veri/data.h>
#include<Formlar/VeriFormlari/gozetmenverigirisi.h>
GozetmenGirisIslemi::GozetmenGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Yeni Gozetmen Girisi"));
    _islem->setIcon(QIcon(":/Resimler/People.png"));
    connect(_islem,&QAction::triggered,this,&GozetmenGirisIslemi::main);

}
void GozetmenGirisIslemi::main()
{
    auto veri =Data::v1().gozetmen().yeniNesne();
    GozetmenVeriGirisi *form=new GozetmenVeriGirisi();
    connect(form,&GozetmenVeriGirisi::veriKaydet,this,&GozetmenGirisIslemi::depoEkle);
    form->setVeri(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

void GozetmenGirisIslemi::depoEkle()
{
    GozetmenVeriGirisi *frmx=dynamic_cast<GozetmenVeriGirisi *>(sender());
    auto veri = frmx->veri();
    Data::v1().gozetmen().nesneEkle(veri);
        frmx->close();
}

QAction *GozetmenGirisIslemi::islem()
{
    return _islem;
}
