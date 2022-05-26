#ifndef SONUC_H
#define SONUC_H

#include "temversinifi.h"

class Sonuc : public TemVerSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(bool basariliMi READ basariliMi WRITE setBasariliMi NOTIFY basariliMiChanged)
    Q_PROPERTY(Metin iyilesmeSuresi READ iyilesmeSuresi WRITE setIyilesmeSuresi NOTIFY iyilesmeSuresiChanged)
    Q_PROPERTY(Metin hastaId READ hastaId WRITE setHastaId NOTIFY hastaIdChanged)

    explicit Sonuc(QObject *parent = nullptr);
    bool basariliMi() const;
    const Metin &iyilesmeSuresi() const;
    const Metin &hastaId() const;

public slots:
    void setBasariliMi(bool newBasariliMi);
    void setIyilesmeSuresi(const Metin &newIyilesmeSuresi);
    void setHastaId(const Metin &newHastaId);
signals:
    void basariliMiChanged(bool newBasariliMi);
    void iyilesmeSuresiChanged(const Metin &newIyilesmeSuresi);
    void hastaIdChanged(const Metin &newHastaId);

private:
    bool _basariliMi;
    Metin _iyilesmeSuresi;
    Metin _hastaId;
    friend QDataStream &operator<<(QDataStream &stream, const Sonuc &veri);
    friend QDataStream &operator>>(QDataStream &stream, Sonuc &veri);

};
QDataStream &operator<<(QDataStream &stream, const Sonuc &veri);
QDataStream &operator>>(QDataStream &stream, Sonuc &veri);

#endif // SONUC_H
