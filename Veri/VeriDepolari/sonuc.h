#ifndef SONUC_H
#define SONUC_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/sonuc.h>
class Sonuc : public QObject,public TemelVeriDeposu<Sonuc>
{
    Q_OBJECT
public:
    explicit Sonuc(QObject *parent = nullptr);

signals:

};

#endif // SONUC_H
