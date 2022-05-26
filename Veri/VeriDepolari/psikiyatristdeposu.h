#ifndef PSIKIYATRISTDEPOSU_H
#define PSIKIYATRISTDEPOSU_H

#include <QObject>
#include"TemelVeriDeposu.h"
#include<Veri/VeriSiniflari/psikiyatrist.h>

class PsikiyatristDeposu : public QObject,public TemelVeriDeposu<Psikiyatrist>
{
    Q_OBJECT
public:
    explicit PsikiyatristDeposu(QObject *parent = nullptr);

signals:
private:
    friend QDataStream &operator<<(QDataStream &stream, const PsikiyatristDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, PsikiyatristDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const PsikiyatristDeposu &veri);
QDataStream &operator>>(QDataStream &stream, PsikiyatristDeposu &veri);
#endif // PSIKIYATRISTDEPOSU_H
