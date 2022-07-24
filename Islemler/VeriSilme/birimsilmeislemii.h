#ifndef BIRIMSILMEISLEMII_H
#define BIRIMSILMEISLEMII_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
#include<Veri/Tanimlar.h>
class BirimSilmeIslemii: public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit BirimSilmeIslemii(QObject *parent = nullptr);

    QAction *islem() override;

    const BirimPtr &veri() const;
    void setVeri(const BirimPtr &newVeri);

    void setIslem(QAction *newIslem);


public slots:
    void main() override;
    //void depoSil();

private:
    QAction * _islem;
    BirimPtr _veri;
};

#endif // BIRIMSILMEISLEMII_H
