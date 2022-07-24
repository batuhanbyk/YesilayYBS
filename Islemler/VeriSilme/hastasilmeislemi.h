#ifndef HASTASILMEISLEMI_H
#define HASTASILMEISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
#include<Veri/Tanimlar.h>
class HastaSilmeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit HastaSilmeIslemi(QObject *parent = nullptr);
    QAction *islem() override;

    const HastaPtr &veri() const;
    void setVeri(const HastaPtr &newVeri);

public slots:
    void main() override;
    //void depoSil();

private:
    QAction * _islem;
    HastaPtr _veri;
};

#endif // HASTASILMEISLEMI_H
