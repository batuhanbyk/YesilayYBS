#include "psikiyatrlisteislemi.h"
#include<Veri/data.h>
#include<Formlar/ListeFormlari/psikiyatrlisteformu.h>
PsikiyatrListeIslemi::PsikiyatrListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Psikiyatr Listesi"));
    _islem->setIcon(QIcon(":/Resimler/People.png"));
    _islem->setShortcut(QKeySequence("F4"));
    connect(_islem,&QAction::triggered,this,&PsikiyatrListeIslemi::main);
}
void PsikiyatrListeIslemi::main()
{
    auto veri =Data::v1().psikiyatrist().tumunuBul([](std::shared_ptr<Psikiyatrist>){return true;});
    PsikiyatrListeFormu *form=new PsikiyatrListeFormu(Data::v1().psikiyatrist());

    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

QAction *PsikiyatrListeIslemi::islem()
{
    return _islem;
}
