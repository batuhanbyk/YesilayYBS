#ifndef BIRIMLISTESI_H
#define BIRIMLISTESI_H

#include <QWidget>
#include<Veri/Tanimlar.h>

namespace Ui {
class BirimListesi;
}

class BirimListesi : public QWidget
{
    Q_OBJECT

public:
    explicit BirimListesi(QWidget *parent = nullptr);
    ~BirimListesi();

private:
    Ui::BirimListesi *ui;
};

#endif // BIRIMLISTESI_H
