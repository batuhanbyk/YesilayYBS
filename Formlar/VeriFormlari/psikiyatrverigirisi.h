#ifndef PSIKIYATRVERIGIRISI_H
#define PSIKIYATRVERIGIRISI_H

#include <QWidget>
#include"TemelVeriGirisi.h"
#include<Veri/VeriSiniflari/psikiyatrist.h>

namespace Ui {
class PsikiyatrVeriGirisi;
}

class PsikiyatrVeriGirisi : public QWidget,public TemelVeriGirisi<PsikiyatrPtr>
{
    Q_OBJECT

public:
    explicit PsikiyatrVeriGirisi(QWidget *parent = nullptr);
    ~PsikiyatrVeriGirisi();

private:
    Ui::PsikiyatrVeriGirisi *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // PSIKIYATRVERIGIRH
