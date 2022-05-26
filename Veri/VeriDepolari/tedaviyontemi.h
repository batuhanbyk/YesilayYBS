#ifndef TEDAVIYONTEMI_H
#define TEDAVIYONTEMI_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/tedaviyontemi.h>
class TedaviYontemi : public QObject,public TemelVeriDeposu<TedaviYontemi>
{
    Q_OBJECT
public:
    explicit TedaviYontemi(QObject *parent = nullptr);

signals:

};

#endif // TEDAVIYONTEMI_H
