#ifndef HASTAVERIGIRISI_H
#define HASTAVERIGIRISI_H

#include <QWidget>
#include"TemelVeriGirisi.h"
#include<Veri/VeriSiniflari/hasta.h>

namespace Ui {
class HastaVeriGirisi;
}

class HastaVeriGirisi : public QWidget,public TemelVeriGirisi<HastaPtr>
{
    Q_OBJECT

public:
    explicit HastaVeriGirisi(QWidget *parent = nullptr);
    ~HastaVeriGirisi();

private:
    Ui::HastaVeriGirisi *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;

    void baslikAta(QString baslik);
signals:
    void veriKaydet();
};

#endif // HASTAVERIGIRISI_H
