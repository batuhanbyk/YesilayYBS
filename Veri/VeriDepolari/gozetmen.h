#ifndef GOZETMEN_H
#define GOZETMEN_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/gozetmen.h>

class Gozetmen : public QObject,public TemelVeriDeposu<Gozetmen>
{
    Q_OBJECT
public:
    explicit Gozetmen(QObject *parent = nullptr);

signals:

};

#endif // GOZETMEN_H
