#ifndef ZIYARET_H
#define ZIYARET_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/ziyaret.h>

class Ziyaret : public QObject,public TemelVeriDeposu<Ziyaret>
{
    Q_OBJECT
public:
    explicit Ziyaret(QObject *parent = nullptr);

signals:

};

#endif // ZIYARET_H
