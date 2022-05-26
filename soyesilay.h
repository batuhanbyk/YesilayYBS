#ifndef SOYESILAY_H
#define SOYESILAY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SOYesilay; }
QT_END_NAMESPACE

class SOYesilay : public QMainWindow
{
    Q_OBJECT

public:
    SOYesilay(QWidget *parent = nullptr);
    ~SOYesilay();


private:
    Ui::SOYesilay *ui;
};
#endif // SOYESILAY_H
