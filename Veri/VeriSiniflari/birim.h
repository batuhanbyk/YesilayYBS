#ifndef BIRIM_H
#define BIRIM_H

#include "temversinifi.h"

class Birim : public TemVerSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin birimAdi READ birimAdi WRITE setBirimAdi NOTIFY birimAdiChanged)
    Q_PROPERTY(Metin birimKodu READ birimKodu WRITE setBirimKodu NOTIFY birimKoduChanged)
    Q_PROPERTY(Metin birimIletisim READ birimIletisim WRITE setBirimIletisim NOTIFY birimIletisimChanged)
    Q_PROPERTY(Metin birimAdresi READ birimAdresi WRITE setBirimAdresi NOTIFY birimAdresiChanged)

    explicit Birim(QObject *parent = nullptr);

    const Metin &birimAdi() const;
    const Metin &birimKodu() const;
    const Metin &birimIletisim() const;

    const Metin &birimAdresi() const;


public slots:
    void setBirimAdi(const Metin &newBirimAdi);
    void setBirimKodu(const Metin &newBirimKodu);
    void setBirimIletisim(const Metin &newBirimIletisim);
    void setBirimAdresi(const Metin &newBirimAdresi);
signals:
    void birimAdiChanged(const Metin &newBirimAdi);
    void birimKoduChanged(const Metin &newBirimKodu);
    void birimIletisimChanged(const Metin &newBirimIletisim);

    void birimAdresiChanged(const Metin &newBirimAdresi);

private:
    Metin _birimAdi;
    Metin _birimKodu;
    Metin _birimIletisim;
    Metin _birimAdresi;
    friend QDataStream &operator<<(QDataStream &stream, const Birim &veri);
    friend QDataStream &operator>>(QDataStream &stream, Birim &veri);

};
QDataStream &operator<<(QDataStream &stream, const Birim &veri);
QDataStream &operator>>(QDataStream &stream, Birim &veri);
#endif // BIRIM_H
