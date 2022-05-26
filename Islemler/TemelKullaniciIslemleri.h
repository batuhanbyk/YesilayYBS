#ifndef TEMELKULLANICIISLEMLERI_H
#define TEMELKULLANICIISLEMLERI_H
#include<QAction>


class TemelKullaniciIslemi{
public:
   virtual void main()=0;
   virtual QAction* islem()=0;
/*Virtual boyle bir fonskiyon mu var benden tureyenler sınıfıyla bu sınıfı degistirebilir*/
};


#endif // TEMELKULLANICIISLEMLERI_H
