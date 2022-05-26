#ifndef PSIKIYATRIST_H
#define PSIKIYATRIST_H

#include "insan.h"

class Psikiyatrist : public Insan
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin psikiyatriAlani READ psikiyatriAlani WRITE setPsikiyatriAlani NOTIFY psikiyatriAlaniChanged)
    Q_PROPERTY(Tamsayi sicilNo READ sicilNo WRITE setSicilNo NOTIFY sicilNoChanged)
    Q_PROPERTY(Tamsayi birimId READ birimId WRITE setBirimId NOTIFY birimIdChanged)

    explicit Psikiyatrist(QObject *parent = nullptr);

    const Metin &psikiyatriAlani() const;
    Tamsayi sicilNo() const;
    Tamsayi birimId() const;
public slots:
    void setPsikiyatriAlani(const Metin &newPsikiyatriAlani);
    void setSicilNo(Tamsayi newSicilNo);
    void setBirimId(Tamsayi newBirimId);

signals:
    void psikiyatriAlaniChanged(const Metin &newPsikiyatriAlani);
    void sicilNoChanged(Tamsayi newSicilNo);
    void birimIdChanged(Tamsayi newBirimId);

private:
    Metin _psikiyatriAlani;
    Tamsayi _sicilNo;
    Tamsayi _birimId;
    friend QDataStream &operator<<(QDataStream &stream, const Psikiyatrist &veri);
    friend QDataStream &operator>>(QDataStream &stream, Psikiyatrist &veri);
};
QDataStream &operator<<(QDataStream &stream, const Psikiyatrist &veri);
QDataStream &operator>>(QDataStream &stream, Psikiyatrist &veri);
#endif // PSIKIYATRIST_H
