#ifndef BAGIMLILIKTURUTESHISDEPOSU_H
#define BAGIMLILIKTURUTESHISDEPOSU_H

#include "TemelVeriDeposu.h"
#include <QObject>
#include<Veri/VeriSiniflari/bagimlilikturuteshis.h>

class BagimlilikTuruTeshisDeposu : public TemelVeriDeposu<BagimlilikTuruTeshis>
{
    Q_OBJECT
public:
    BagimlilikTuruTeshisDeposu();
};

#endif // BAGIMLILIKTURUTESHISDEPOSU_H
