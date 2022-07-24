#ifndef PSIKIYATRLISTEFORMU_H
#define PSIKIYATRLISTEFORMU_H

#include <QWidget>
#include <Veri/Tanimlar.h>
namespace Ui {
class PsikiyatrListeFormu;
}
class PsikiyatrFiltrelemeFonksiyonu{

public:
    typedef enum{
        FiltreIleBaslayan=1,
        FiltreIleBiten=2,
        FiltreIceren=4,
    } FiltrelemeTuru;

    bool operator()(PsikiyatrPtr data);

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
class PsikiyatrListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit PsikiyatrListeFormu(PsikiyatristDeposu &depo,QWidget *parent = nullptr);
    ~PsikiyatrListeFormu();

    const PsikiyatrListesi &liste() const;
    const PsikiyatrListesi &liste1() const;

public slots:
    void setListe(const PsikiyatrListesi &newListe);
    void setListe1(const PsikiyatrListesi &newListe1);
private slots:
    void on_btnAra_clicked();

private:
    Ui::PsikiyatrListeFormu *ui;
    PsikiyatrListesi _liste;

    PsikiyatrListesi _liste1;
    PsikiyatristDeposu &_depo;
    void ekranGuncelle();
};

#endif // PSIKIYATRLISTEFORMU_H
