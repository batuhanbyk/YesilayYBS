#ifndef HASTAGIRISISLEMI_H
#define HASTAGIRISISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class HastaGirisIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit HastaGirisIslemi(QObject *parent = nullptr);

signals:


    // TemelKullaniciIslemi interface
public slots:
    void main() override;
    void depoEkle();
public:

    QAction *islem() override;
private:
    QAction * _islem;
};


#endif // HASTAGIRISISLEMI_H
