#ifndef INSAN_H
#define INSAN_H

#include "temversinifi.h"

class Insan : public TemVerSinifi
{
    Q_OBJECT


public:
    Q_PROPERTY(Metin tcKimlik READ tcKimlik WRITE setTcKimlik NOTIFY tcKimlikChanged)
    Q_PROPERTY(Metin ad READ ad WRITE setAd NOTIFY adChanged)
    Q_PROPERTY(Metin soyad READ soyad WRITE setSoyad NOTIFY soyadChanged)
    Q_PROPERTY(Metin dogumTarihi READ dogumTarihi WRITE setDogumTarihi NOTIFY dogumTarihiChanged)
    Q_PROPERTY(Cinsiyet cinsiyeti READ cinsiyeti WRITE setCinsiyeti NOTIFY cinsiyetiChanged)
    Q_PROPERTY(Tarih dogumTarihi1 READ dogumTarihi1 WRITE setDogumTarihi1 NOTIFY dogumTarihi1Changed)

    explicit Insan(QObject *parent = nullptr);

    const Metin &tcKimlik() const;
    const Metin &ad() const;
    const Metin &soyad() const;
    const Metin &dogumTarihi() const;
    Cinsiyet cinsiyeti() const;

    const Tarih &dogumTarihi1() const;


public slots:
    void setTcKimlik(const Metin &newTcKimlik);
    void setAd(const Metin &newAd);
    void setSoyad(const Metin &newSoyad);
    void setDogumTarihi(const Metin &newDogumTarihi);
    void setCinsiyeti(Cinsiyet newCinsiyeti);
    void setDogumTarihi1(const Tarih &newDogumTarihi1);
signals:
    void tcKimlikChanged(const Metin &newTcKimlik);
    void adChanged(const Metin &newAd);
    void soyadChanged(const Metin &newSoyad);
    void dogumTarihiChanged(const Metin &newDogumTarihi);
    void cinsiyetiChanged(Cinsiyet newCinsiyeti); 
    void dogumTarihi1Changed(const Tarih &newDogumTarihi1);

protected:
    Metin _tcKimlik;
    Metin _ad;
    Metin _soyad;
    Metin _dogumTarihi;
    Tarih _dogumTarihi1;
    Cinsiyet _cinsiyeti;
};

#endif // INSAN_H
