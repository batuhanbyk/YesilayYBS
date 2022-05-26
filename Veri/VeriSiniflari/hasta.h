#ifndef HASTA_H
#define HASTA_H

#include "insan.h"

class Hasta : public Insan
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin oykusu READ oykusu WRITE setOykusu NOTIFY oykusuChanged)
    Q_PROPERTY(Tamsayi psikiyatrId READ psikiyatrId WRITE setPsikiyatrId NOTIFY psikiyatrIdChanged)
    Q_PROPERTY(Tamsayi bagimlilikTuruTeshisId READ bagimlilikTuruTeshisId WRITE setBagimlilikTuruTeshisId NOTIFY bagimlilikTuruTeshisIdChanged)

    explicit Hasta(QObject *parent = nullptr);

    const Metin &oykusu() const;
    Tamsayi psikiyatrId() const;
    Tamsayi bagimlilikTuruTeshisId() const;

public slots:
    void setOykusu(const Metin &newOykusu);
    void setPsikiyatrId(Tamsayi newPsikiyatrId);
    void setBagimlilikTuruTeshisId(Tamsayi newBagimlilikTuruTeshisId);

signals:
    void oykusuChanged(const Metin &newOykusu);
    void psikiyatrIdChanged(Tamsayi newPsikiyatrId);
    void bagimlilikTuruTeshisIdChanged(Tamsayi newBagimlilikTuruTeshisId);

private:
    Metin _oykusu;
    Tamsayi _psikiyatrId;
    Tamsayi _bagimlilikTuruTeshisId;
    friend QDataStream &operator<<(QDataStream &stream, const Hasta &veri);
    friend QDataStream &operator>>(QDataStream &stream, Hasta &veri);
};
QDataStream &operator<<(QDataStream &stream, const Hasta &veri);
QDataStream &operator>>(QDataStream &stream, Hasta &veri);
#endif // HASTA_H
