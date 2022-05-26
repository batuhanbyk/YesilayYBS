#ifndef GOZETMENVERIGIRISI_H
#define GOZETMENVERIGIRISI_H

#include <QWidget>
#include"TemelVeriGirisi.h"
#include<Veri/VeriSiniflari/gozetmen.h>

namespace Ui {
class GozetmenVeriGirisi;
}

class GozetmenVeriGirisi : public QWidget,public TemelVeriGirisi<GozetmenPtr>
{
    Q_OBJECT

public:
    explicit GozetmenVeriGirisi(QWidget *parent = nullptr);
    ~GozetmenVeriGirisi();

private:
    Ui::GozetmenVeriGirisi *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
};

#endif // GOZETMENVERIGIRISI_H
