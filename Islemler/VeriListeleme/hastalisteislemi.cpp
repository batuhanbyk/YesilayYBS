#include "hastalisteislemi.h"
#include<Veri/data.h>
#include<Formlar/ListeFormlari/hastalisteformu.h>
HastaListeIslemi::HastaListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Hasta Listesi"));
    _islem->setIcon(QIcon(":/Resimler/People.png"));
    _islem->setShortcut(QKeySequence("F3"));
    connect(_islem,&QAction::triggered,this,&HastaListeIslemi::main);
}

void HastaListeIslemi::main()
{
    auto veri =Data::v1().hasta().tumunuBul([](std::shared_ptr<Hasta>){return true;});
    HastaListeFormu *form=new HastaListeFormu(Data::v1().hasta());

    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

QAction *HastaListeIslemi::islem()
{
     return _islem;
}
