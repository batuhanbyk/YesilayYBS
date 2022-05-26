#ifndef BIRIM_H
#define BIRIM_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/birim.h>

class Birim : public QObject,public TemelVeriDeposu<Birim>
{
    Q_OBJECT
public:
    explicit Birim(QObject *parent = nullptr);

signals:

};

#endif // BIRIM_H
