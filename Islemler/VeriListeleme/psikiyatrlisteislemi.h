#ifndef PSIKIYATRLISTEISLEMI_H
#define PSIKIYATRLISTEISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class PsikiyatrListeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit PsikiyatrListeIslemi(QObject *parent = nullptr);

signals:


    // TemelKullaniciIslemi interface
public slots:
    void main() override;
public:

    QAction *islem() override;
private:
    QAction *_islem;
};



#endif // PSIKIYATRLISTEISLEMI_H
