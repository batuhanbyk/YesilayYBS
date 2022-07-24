#ifndef GOZETMENLISTEISLEMI_H
#define GOZETMENLISTEISLEMI_H

#include <QObject>
#include<Islemler/TemelKullaniciIslemleri.h>
class GozetmenListeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit GozetmenListeIslemi(QObject *parent = nullptr);

signals:

private:
    QAction *_islem;

    // TemelKullaniciIslemi interface
public slots:
    void main() override;
public:
    QAction *islem() override;
};



#endif // GOZETMENLISTEISLEMI_H
