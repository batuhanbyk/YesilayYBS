#ifndef HASTA_H
#define HASTA_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/hasta.h>

class Hasta : public QObject,public TemelVeriDeposu<Hasta>
{
    Q_OBJECT
public:
    explicit Hasta(QObject *parent = nullptr);

signals:

};

#endif // HASTA_H
