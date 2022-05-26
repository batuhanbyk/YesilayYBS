#ifndef ZIYARET_H
#define ZIYARET_H

#include "temversinifi.h"

class Ziyaret : public TemVerSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin sikayeti READ sikayeti WRITE setSikayeti NOTIFY sikayetiChanged)
    Q_PROPERTY(Tarih gelisTarihi READ gelisTarihi WRITE setGelisTarihi NOTIFY gelisTarihiChanged)
    Q_PROPERTY(Tamsayi hastaId READ hastaId WRITE setHastaId NOTIFY hastaIdChanged)
    Q_PROPERTY(Tamsayi gozetmenId READ gozetmenId WRITE setGozetmenId NOTIFY gozetmenIdChanged)
    Q_PROPERTY(Tamsayi psikiyatrId READ psikiyatrId WRITE setPsikiyatrId NOTIFY psikiyatrIdChanged)
    Q_PROPERTY(Tamsayi tedaviYontemiId READ tedaviYontemiId WRITE setTedaviYontemiId NOTIFY tedaviYontemiIdChanged)
    Q_PROPERTY(Tamsayi bagimlilikTuruTeshisId READ bagimlilikTuruTeshisId WRITE setBagimlilikTuruTeshisId NOTIFY bagimlilikTuruTeshisIdChanged)
    Q_PROPERTY(Tamsayi birimId READ birimId WRITE setBirimId NOTIFY birimIdChanged)

    explicit Ziyaret(QObject *parent = nullptr);

    const Metin &sikayeti() const;
    const Tarih &gelisTarihi() const;
    Tamsayi hastaId() const;
    Tamsayi gozetmenId() const;
    Tamsayi psikiyatrId() const;
    Tamsayi tedaviYontemiId() const;
    Tamsayi bagimlilikTuruTeshisId() const;
    Tamsayi birimId() const;

public slots:
    void setSikayeti(const Metin &newSikayeti);
    void setGelisTarihi(const Tarih &newGelisTarihi);
    void setHastaId(Tamsayi newHastaId);
    void setGozetmenId(Tamsayi newGozetmenId);
    void setPsikiyatrId(Tamsayi newPsikiyatrId);
    void setTedaviYontemiId(Tamsayi newTedaviYontemiId);
    void setBagimlilikTuruTeshisId(Tamsayi newBagimlilikTuruTeshisId);
    void setBirimId(Tamsayi newBirimId);

signals:
    void sikayetiChanged(const Metin &newSikayeti);
    void gelisTarihiChanged(const Tarih &newGelisTarihi);
    void hastaIdChanged(Tamsayi newHastaId);
    void gozetmenIdChanged(Tamsayi newGozetmenId);
    void psikiyatrIdChanged(Tamsayi newPsikiyatrId);
    void tedaviYontemiIdChanged(Tamsayi newTedaviYontemiId);
    void bagimlilikTuruTeshisIdChanged(Tamsayi newBagimlilikTuruTeshisId);
    void birimIdChanged(Tamsayi newBirimId);

private:
    Metin _sikayeti;
    Tarih _gelisTarihi;
    Tamsayi _hastaId;
    Tamsayi _gozetmenId;
    Tamsayi _psikiyatrId;
    Tamsayi _tedaviYontemiId;
    Tamsayi _bagimlilikTuruTeshisId;
    Tamsayi _birimId;
    friend QDataStream &operator<<(QDataStream &stream, const Ziyaret &veri);
    friend QDataStream &operator>>(QDataStream &stream, Ziyaret &veri);
};
QDataStream &operator<<(QDataStream &stream, const Ziyaret &veri);
QDataStream &operator>>(QDataStream &stream, Ziyaret &veri);
#endif // ZIYARET_H
