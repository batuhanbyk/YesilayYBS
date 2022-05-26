#ifndef BIRIMLISTEISLEMI_H
#define BIRIMLISTEISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class BirimListeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit BirimListeIslemi(QObject *parent = nullptr);

signals:


private:
    QAction *_islem;



    // TemelKullaniciIslemi interface
public slots:
    void main() override;
public:
    QAction *islem() override;
};



#endif // BIRIMLISTEISLEMI_H
