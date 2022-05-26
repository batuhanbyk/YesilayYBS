#include "bagimlilikturuteshisdepo.h"

BagimlilikTuruTeshisDepo::BagimlilikTuruTeshisDepo(QObject *parent)
    : QObject{parent},TemelVeriDeposu<BagimlilikTuruTeshis>{}
{

}
QDataStream &operator<<(QDataStream &stream, const BagimlilikTuruTeshisDepo &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, BagimlilikTuruTeshisDepo &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
