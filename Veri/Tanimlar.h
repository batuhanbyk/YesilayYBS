#ifndef TANIMLAR_H
#define TANIMLAR_H

#include<QDateTime>
#include <QList>
#include <QString>
#include <memory>
#include<QStringList>
#include<QDir>
#include<QStandardPaths>
#include<QSize>

typedef QString Metin;
typedef int Tamsayi;
typedef enum { Kadin = 1, Erkek = 2 } Cinsiyet;
typedef QDate Tarih;
typedef QTime Saat;
typedef QDateTime TarihSaat;

class Psikiyatrist;
class Hasta;
class Gozetmen;
class Birim;
class Ziyaret;
class TedaviYontemi;
class BagimlilikTuruTeshis;
class Sonuc;

typedef std::shared_ptr<Psikiyatrist> PsikiyatrPtr;
typedef std::shared_ptr<Gozetmen> GozetmenPtr;
typedef std::shared_ptr<TedaviYontemi> TedaviYontemiPtr;
typedef std::shared_ptr<Hasta> HastaPtr;
typedef std::shared_ptr<Ziyaret> ZiyaretPtr;
typedef std::shared_ptr<BagimlilikTuruTeshis> BagimlilikTuruTeshisPtr;
typedef std::shared_ptr<Sonuc> SonucPtr;
typedef std::shared_ptr<Birim> BirimPtr;

typedef QList<PsikiyatrPtr> PsikiyatrListesi;
typedef QList<GozetmenPtr> GozetmenListesi;
typedef QList<TedaviYontemiPtr> TedaviYontemiListesi;
typedef QList<HastaPtr> HastaListesi;
typedef QList<ZiyaretPtr> ZiyaretListesi;
typedef QList<BagimlilikTuruTeshisPtr> BagimlilikTuruTeshisListesi;
typedef QList<SonucPtr> SonucListesi;
typedef QList<BirimPtr> BirimListesi;

class PsikiyatrDeposu;
class HastaDeposu;
class GozetmenDeposu;
class BirimDeposu;
class ZiyaretDeposu;
class TedaviYontemiDeposu;
class BagimlilikTuruTeshisDeposu;
class SonucDeposu;

#endif // TANIMLAR_H
