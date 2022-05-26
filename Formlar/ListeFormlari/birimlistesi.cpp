#include "birimlistesi.h"
#include "ui_birimlistesi.h"

BirimListesi::BirimListesi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BirimListesi)
{
    ui->setupUi(this);
}

BirimListesi::~BirimListesi()
{
    delete ui;
}
