#include "birimlisteislemi.h"
#include<Veri/data.h>
#include<Formlar/ListeFormlari/birimlisteformu.h>
BirimListeIslemi::BirimListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Birim Listesi"));
    _islem->setIcon(QIcon(":/Resimler/Birim.png"));
    _islem->setShortcut(QKeySequence("F1"));
    connect(_islem,&QAction::triggered,this,&BirimListeIslemi::main);
}

void BirimListeIslemi::main()
{
    auto veri =Data::v1().birim().tumunuBul([](std::shared_ptr<Birim>){return true;});
    BirimListeFormu *form=new BirimListeFormu(Data::v1().birim());

    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

QAction *BirimListeIslemi::islem()
{
    return _islem;
}

