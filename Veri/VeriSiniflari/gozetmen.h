#ifndef GOZETMEN_H
#define GOZETMEN_H

#include "insan.h"

class Gozetmen : public Insan
{
    Q_OBJECT
public:
    Q_PROPERTY(Tamsayi sicilNo READ sicilNo WRITE setSicilNo NOTIFY sicilNoChanged)
    Q_PROPERTY(Tamsayi birimId READ birimId WRITE setBirimId NOTIFY birimIdChanged)

    explicit Gozetmen(QObject *parent = nullptr);

    Tamsayi sicilNo() const;
    Tamsayi birimId() const;

public slots:
     void setSicilNo(Tamsayi newSicilNo);
     void setBirimId(Tamsayi newBirimId);

signals:
    void sicilNoChanged(Tamsayi newSicilNo);
    void birimIdChanged(Tamsayi newBirimId);

private:
    Tamsayi _sicilNo;
    Tamsayi _birimId;
    friend QDataStream &operator<<(QDataStream &stream, const Gozetmen &veri);
    friend QDataStream &operator>>(QDataStream &stream, Gozetmen &veri);
};
QDataStream &operator<<(QDataStream &stream, const Gozetmen &veri);
QDataStream &operator>>(QDataStream &stream, Gozetmen &veri);

#endif // GOZETMEN_H
