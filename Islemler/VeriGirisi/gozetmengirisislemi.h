#ifndef GOZETMENGIRISISLEMI_H
#define GOZETMENGIRISISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class GozetmenGirisIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit GozetmenGirisIslemi(QObject *parent = nullptr);

signals:



    // TemelKullaniciIslemi interface
public:
    QAction *islem() override;
public slots:
    void main() override;
    void depoEkle();
private:
    QAction * _islem;
};



#endif // GOZETMENGIRISISLEMI_H
