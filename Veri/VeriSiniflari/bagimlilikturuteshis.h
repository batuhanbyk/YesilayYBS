#ifndef BAGIMLILIKTURUTESHIS_H
#define BAGIMLILIKTURUTESHIS_H

#include "temversinifi.h"

class BagimlilikTuruTeshis : public TemVerSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin bagimlilikTuru READ bagimlilikTuru WRITE setBagimlilikTuru NOTIFY bagimlilikTuruChanged)
    Q_PROPERTY(Metin bagimlilikKademesi READ bagimlilikKademesi WRITE setBagimlilikKademesi NOTIFY bagimlilikKademesiChanged)
    Q_PROPERTY(Tamsayi hastaId READ hastaId WRITE setHastaId NOTIFY hastaIdChanged)

    explicit BagimlilikTuruTeshis(QObject *parent = nullptr);

    const Metin &bagimlilikTuru() const;
    const Metin &bagimlilikKademesi() const;
    Tamsayi hastaId() const;

public slots:
    void setBagimlilikTuru(const Metin &newBagimlilikTuru);
    void setBagimlilikKademesi(const Metin &newBagimlilikKademesi);
    void setHastaId(Tamsayi newHastaId);
signals:
    void bagimlilikTuruChanged(const Metin &newBagimlilikTuru);
    void bagimlilikKademesiChanged(const Metin &newBagimlilikKademesi);
    void hastaIdChanged(Tamsayi newHastaId);

private:
    Metin _bagimlilikTuru;
    Metin _bagimlilikKademesi;
    Tamsayi _hastaId;
    friend QDataStream &operator<<(QDataStream &stream, const BagimlilikTuruTeshis &veri);
    friend QDataStream &operator>>(QDataStream &stream, BagimlilikTuruTeshis &veri);

};

QDataStream &operator<<(QDataStream &stream, const BagimlilikTuruTeshis &veri);
QDataStream &operator>>(QDataStream &stream, BagimlilikTuruTeshis &veri);



#endif // BAGIMLILIKTURUTESHIS_H
