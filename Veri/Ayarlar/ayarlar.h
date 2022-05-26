#ifndef AYARLAR_H
#define AYARLAR_H

#include <QObject>
#include "../Tanimlar.h"

class Ayarlar : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(Tamsayi ocakId READ ocakId WRITE setOcakId NOTIFY ocakIdChanged)
    static Ayarlar &ayar();
    ~Ayarlar();
    Tamsayi ocakId() const;

public slots:
    void setOcakId(Tamsayi newOcakId);
signals:
    void ocakIdChanged(Tamsayi newOcakId);

private:
    explicit Ayarlar(QObject *parent = nullptr);
    Tamsayi _ocakId;

};

#endif // AYARLAR_H
