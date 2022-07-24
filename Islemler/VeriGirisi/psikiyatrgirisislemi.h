#ifndef PSIKIYATRGIRISISLEMI_H
#define PSIKIYATRGIRISISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class PsikiyatrGirisIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit PsikiyatrGirisIslemi(QObject *parent = nullptr);

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

#endif // PSIKIYATRGIRISISLEMI_H
