#ifndef GOZETMENLISTEFORMU_H
#define GOZETMENLISTEFORMU_H

#include <QWidget>
#include <Veri/Tanimlar.h>

namespace Ui {
class GozetmenListeFormu;
}
class GozetmenFiltrelemeFonksiyonu{

public:
    typedef enum{
        FiltreIleBaslayan=1,
        FiltreIleBiten=2,
        FiltreIceren=4,
    } FiltrelemeTuru;

    bool operator()(GozetmenPtr data);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

    FiltrelemeTuru filtre() const;
    void setFiltre(FiltrelemeTuru newFiltre);

    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;
};
class GozetmenListeFormu : public QWidget
{
    Q_OBJECT

public:
    explicit GozetmenListeFormu(GozetmenDeposu &depo,QWidget *parent = nullptr);
    ~GozetmenListeFormu();

    const GozetmenListesi &liste() const;
    const GozetmenListesi &liste1() const;

public slots:
    void setListe(const GozetmenListesi &newListe);
    void setListe1(const GozetmenListesi &newListe1);
private slots:
    void on_btnAra_clicked();
private:
    Ui::GozetmenListeFormu *ui;
    GozetmenListesi _liste;
    GozetmenListesi _liste1;
    GozetmenDeposu &_depo;
    void ekranGuncelle();
};

#endif // GOZETMENLISTEFORMU_H
