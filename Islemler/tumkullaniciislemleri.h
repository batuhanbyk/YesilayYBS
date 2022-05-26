#ifndef TUMKULLANICIISLEMLERI_H
#define TUMKULLANICIISLEMLERI_H

#include <QObject>
#include"TemelKullaniciIslemleri.h"
#include<QList>
#include<memory.h>

class TumKullaniciIslemleri : public QObject
{
    Q_OBJECT
public:
    static TumKullaniciIslemleri &v1v();
void islemCalistir(int sira_no);
QAction *islem(int sira_no);
signals:
private:
explicit TumKullaniciIslemleri(QObject *parent = nullptr);
    QList<std::shared_ptr<TemelKullaniciIslemi>> _islemler;

};

#endif // TUMKULLANICIISLEMLERI_H
