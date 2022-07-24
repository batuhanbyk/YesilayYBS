#ifndef HASTALISTEISLEMI_H
#define HASTALISTEISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class HastaListeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit HastaListeIslemi(QObject *parent = nullptr);

signals:


    // TemelKullaniciIslemi interface
public slots:
    void main() override;
public:

    QAction *islem() override;
private:
    QAction *_islem;
};


#endif // HASTALISTEISLEMI_H
