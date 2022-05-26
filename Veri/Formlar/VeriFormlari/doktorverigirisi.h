#ifndef DOKTORVERIGIRISI_H
#define DOKTORVERIGIRISI_H

#include <QWidget>

namespace Ui {
class DoktorVeriGirisi;
}

class DoktorVeriGirisi : public QWidget
{
    Q_OBJECT

public:
    explicit DoktorVeriGirisi(QWidget *parent = nullptr);
    ~DoktorVeriGirisi();

private:
    Ui::DoktorVeriGirisi *ui;
};

#endif // DOKTORVERIGIRISI_H
