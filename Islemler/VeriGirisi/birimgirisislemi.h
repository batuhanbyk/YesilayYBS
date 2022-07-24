#ifndef BIRIMGIRISISLEMI_H
#define BIRIMGIRISISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>

class BirimGirisIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit BirimGirisIslemi(QObject *parent = nullptr);

signals:


    // TemelKullaniciIslemi interface
public:

    QAction *islem() override;
public slots:
    void main() override;
    void depoEkle();
private:
 QAction *_islem;
};

#endif // BIRIMGIRISISLEMI_H
