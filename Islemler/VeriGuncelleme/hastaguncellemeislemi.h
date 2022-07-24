#ifndef HASTAGUNCELLEMEISLEMI_H
#define HASTAGUNCELLEMEISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemleri.h>
#include <Veri/Tanimlar.h>
class HastaGuncellemeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit HastaGuncellemeIslemi(QObject *parent = nullptr);

signals:
    void islemTamamlandi();
private:
    QAction *_islem;
    HastaPtr _veri;

    // TemelKullaniciIslemi interface
public:
    QAction *islem() override;
    const HastaPtr &veri() const;


public slots:
    void qMain() override;
    void setVeri(const HastaPtr &newVeri);
    void depoGuncelle();
};

#endif // HASTAGUNCELLEMEISLEMI_H
