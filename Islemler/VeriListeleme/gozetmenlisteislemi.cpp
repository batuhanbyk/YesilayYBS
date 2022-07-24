#include "gozetmenlisteislemi.h"
#include<Veri/data.h>
#include<Formlar/ListeFormlari/gozetmenlisteformu.h>
GozetmenListeIslemi::GozetmenListeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem =new QAction();
    _islem->setText(tr("Gozetmen Listesi"));
    _islem->setIcon(QIcon(":/Resimler/People.png"));
    _islem->setShortcut(QKeySequence("F2"));
    connect(_islem,&QAction::triggered,this,&GozetmenListeIslemi::main);
}
void GozetmenListeIslemi::main()
{
    auto veri =Data::v1().gozetmen().tumunuBul([](std::shared_ptr<Gozetmen>){return true;});
    GozetmenListeFormu *form=new GozetmenListeFormu(Data::v1().gozetmen());

    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}

QAction *GozetmenListeIslemi::islem()
{
    return _islem;
}
