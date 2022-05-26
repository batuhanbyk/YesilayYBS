#ifndef BIRIMLISTEFORMU_H
#define BIRIMLISTEFORMU_H

#include <QWidget>
#include <Veri/Tanimlar.h>
namespace Ui {
class BirimListeFormu;
}

class BirimFiltrelemeFonksiyonu{

public:
    typedef enum{
        FiltreIleBaslayan=1,
        FiltreIleBiten=2,
        FiltreIceren=4,
    } FiltrelemeTuru;
    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

    FiltrelemeTuru filtre() const;
    void setFiltre(FiltrelemeTuru newFiltre);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

    bool operator()(BirimPtr data);

private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;
};

class BirimListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit BirimListeFormu(BirimDeposu &depo,QWidget *parent = nullptr);
    ~BirimListeFormu();

    const BirimListesi &liste() const;
    const BirimListesi &liste1() const;


public slots:
    void setListe(const BirimListesi &newListe);
    void setListe1(const BirimListesi &newListe1);
private slots:
    void on_btnAra_clicked();

private:
    Ui::BirimListeFormu *ui;
    BirimListesi _liste;

    BirimListesi _liste1;
    BirimDeposu &_depo;
    void ekranGuncelle();
};

#endif // BIRIMLISTEFORMU_H
