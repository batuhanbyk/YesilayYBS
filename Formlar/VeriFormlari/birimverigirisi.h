#ifndef BIRIMVERIGIRISI_H
#define BIRIMVERIGIRISI_H

#include <QWidget>
#include<Formlar/VeriFormlari/TemelVeriGirisi.h>
#include<Veri/VeriSiniflari/birim.h>

namespace Ui {
class BirimVeriGirisi;
}

class BirimVeriGirisi : public QWidget, public TemelVeriGirisi<BirimPtr>
{
    Q_OBJECT

public:
    explicit BirimVeriGirisi(QWidget *parent = nullptr);
    ~BirimVeriGirisi();

private:
    Ui::BirimVeriGirisi *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle();
    void veriGuncelle();
signals:
    void veriKaydet();
};

#endif // BIRIMVERIGIRISI_H
