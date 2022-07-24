#ifndef HASTALISTEFORMU_H
#define HASTALISTEFORMU_H

#include <QWidget>
#include <Veri/Tanimlar.h>

namespace Ui {
class HastaListeFormu;
}

class HastaFiltrelemeFonksiyonu{

public:
    typedef enum{
        FiltreIleBaslayan=1,
        FiltreIleBiten=2,
        FiltreIceren=4,
    } FiltrelemeTuru;

    bool operator()(HastaPtr data);

    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

    FiltrelemeTuru filtre() const;
    void setFiltre(FiltrelemeTuru newFiltre);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;
};
class HastaListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit HastaListeFormu(HastaDeposu &depo,QWidget *parent = nullptr);
    ~HastaListeFormu();

    const HastaListesi &liste1() const;
    const HastaListesi &liste() const;

public slots:
    void setListe1(const HastaListesi &newListe1);
    void setListe(const HastaListesi &newListe);
private slots:
    void on_btnAra_clicked();
private:
    Ui::HastaListeFormu *ui;
    HastaListesi _liste;

    HastaListesi _liste1;
    HastaDeposu &_depo;
    void ekranGuncelle();
};

#endif // HASTALISTEFORMU_H
