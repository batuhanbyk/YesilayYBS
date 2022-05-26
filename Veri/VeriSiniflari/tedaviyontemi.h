#ifndef TEDAVIYONTEMI_H
#define TEDAVIYONTEMI_H

#include "temversinifi.h"

class TedaviYontemi : public TemVerSinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin tibbi READ tibbi WRITE setTibbi NOTIFY tibbiChanged)
    Q_PROPERTY(Metin psikolojik READ psikolojik WRITE setPsikolojik NOTIFY psikolojikChanged)

    explicit TedaviYontemi(QObject *parent = nullptr);

    const Metin &tibbi() const;
    const Metin &psikolojik() const;

public slots:
    void setTibbi(const Metin &newTibbi);
    void setPsikolojik(const Metin &newPsikolojik);

signals:
    void tibbiChanged(const Metin &newTibbi);
    void psikolojikChanged(const Metin &newPsikolojik);

private:
    Metin _tibbi;
    Metin _psikolojik;
    friend QDataStream &operator>>(QDataStream &stream, TedaviYontemi &veri);
    friend QDataStream &operator<<(QDataStream &stream, const TedaviYontemi &veri);
};
QDataStream &operator<<(QDataStream &stream, const TedaviYontemi &veri);
QDataStream &operator>>(QDataStream &stream, TedaviYontemi &veri);

#endif // TEDAVIYONTEMI_H
