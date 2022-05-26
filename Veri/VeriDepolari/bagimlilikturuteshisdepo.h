#ifndef BAGIMLILIKTURUTESHISDEPO_H
#define BAGIMLILIKTURUTESHISDEPO_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/bagimlilikturuteshis.h>

class BagimlilikTuruTeshisDepo : public QObject,public TemelVeriDeposu<BagimlilikTuruTeshis>
{
    Q_OBJECT
public:
    explicit BagimlilikTuruTeshisDepo(QObject *parent = nullptr);

signals:
private:
   friend QDataStream &operator<<(QDataStream &stream, const BagimlilikTuruTeshisDepo &veri);
   friend QDataStream &operator>>(QDataStream &stream, BagimlilikTuruTeshisDepo &veri);
};
QDataStream &operator<<(QDataStream &stream, const BagimlilikTuruTeshisDepo &veri);
QDataStream &operator>>(QDataStream &stream, BagimlilikTuruTeshisDepo &veri);

#endif // BAGIMLILIKTURUTESHISDEPO_H
