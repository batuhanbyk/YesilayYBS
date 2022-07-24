#ifndef ISLEMDEPOSU_H
#define ISLEMDEPOSU_H

#include <QObject>
#include<QList>
#include"TemelKullaniciIslemleri.h"
#include<memory>
class IslemDeposu : public QObject
{
    Q_OBJECT
public:
    static IslemDeposu &v1vv();
    typedef enum{ IslemBirimGiris=0,
                  IslemSaglikOcagiListe,
                  IslemSaglikOcagiSil,
                  IslemGozetmenGiris,
                  IslemGozetmenListe,
                  IslemHastaGiris,
                  IslemHastaListe,
                  IslemPsikiyatristGiris,
                  IslemPsikiyatristListe,
                  IslemHastaSil,
                  IslemHastaGuncelle} IslemSirasi ;

    QAction *getAction(IslemSirasi x);
    void calistir(IslemSirasi y);
    std::shared_ptr<TemelKullaniciIslemi> getIslem(IslemSirasi z);

private:
    explicit IslemDeposu(QObject *parent = nullptr);
    QList<std::shared_ptr<TemelKullaniciIslemi>> _islemler;

signals:

};

#endif // ISLEMDEPOSU_H
