#include "psikiyatristdeposu.h"

PsikiyatristDeposu::PsikiyatristDeposu(QObject *parent)
    : QObject{parent},TemelVeriDeposu<Psikiyatrist>{}
{

}
QDataStream &operator<<(QDataStream &stream, const PsikiyatristDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, PsikiyatristDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
