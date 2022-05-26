QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Formlar/ListeFormlari/birimlisteformu.cpp \
    Formlar/VeriFormlari/birimverigirisi.cpp \
    Formlar/VeriFormlari/gozetmenverigirisi.cpp \
    Formlar/VeriFormlari/hastaverigirisi.cpp \
    Formlar/VeriFormlari/psikiyatrverigirisi.cpp \
    Islemler/VeriGirisi/birimgirisislemi.cpp \
    Islemler/VeriListeleme/birimlisteislemi.cpp \
    Islemler/islemdeposu.cpp \
    Islemler/tumkullaniciislemleri.cpp \
    Veri/Ayarlar/ayarlar.cpp \
    Veri/VeriDepolari/bagimlilikturuteshisdepo.cpp \
    Veri/VeriDepolari/birimdeposu.cpp \
    Veri/VeriDepolari/gozetmendeposu.cpp \
    Veri/VeriDepolari/hastadeposu.cpp \
    Veri/VeriDepolari/psikiyatristdeposu.cpp \
    Veri/VeriDepolari/sonucdeposu.cpp \
    Veri/VeriDepolari/tedaviyontemideposu.cpp \
    Veri/VeriDepolari/ziyaretdeposu.cpp \
    Veri/VeriSiniflari/bagimlilikturuteshis.cpp \
    Veri/VeriSiniflari/birim.cpp \
    Veri/VeriSiniflari/gozetmen.cpp \
    Veri/VeriSiniflari/hasta.cpp \
    Veri/VeriSiniflari/insan.cpp \
    Veri/VeriSiniflari/psikiyatrist.cpp \
    Veri/VeriSiniflari/sonuc.cpp \
    Veri/VeriSiniflari/tedaviyontemi.cpp \
    Veri/VeriSiniflari/temversinifi.cpp \
    Veri/VeriSiniflari/ziyaret.cpp \
    Veri/data.cpp \
    main.cpp \
    soyesilay.cpp

HEADERS += \
    Formlar/ListeFormlari/birimlisteformu.h \
    Formlar/VeriFormlari/TemelVeriGirisi.h \
    Formlar/VeriFormlari/birimverigirisi.h \
    Formlar/VeriFormlari/gozetmenverigirisi.h \
    Formlar/VeriFormlari/hastaverigirisi.h \
    Formlar/VeriFormlari/psikiyatrverigirisi.h \
    Islemler/TemelKullaniciIslemleri.h \
    Islemler/VeriGirisi/birimgirisislemi.h \
    Islemler/VeriListeleme/birimlisteislemi.h \
    Islemler/islemdeposu.h \
    Islemler/tumkullaniciislemleri.h \
    Veri/Ayarlar/ayarlar.h \
    Veri/Tanimlar.h \
    Veri/VeriDepolari/TemelVeriDeposu.h \
    Veri/VeriDepolari/bagimlilikturuteshisdepo.h \
    Veri/VeriDepolari/birimdeposu.h \
    Veri/VeriDepolari/gozetmendeposu.h \
    Veri/VeriDepolari/hastadeposu.h \
    Veri/VeriDepolari/psikiyatristdeposu.h \
    Veri/VeriDepolari/sonucdeposu.h \
    Veri/VeriDepolari/tedaviyontemideposu.h \
    Veri/VeriDepolari/ziyaretdeposu.h \
    Veri/VeriSiniflari/bagimlilikturuteshis.h \
    Veri/VeriSiniflari/birim.h \
    Veri/VeriSiniflari/gozetmen.h \
    Veri/VeriSiniflari/hasta.h \
    Veri/VeriSiniflari/insan.h \
    Veri/VeriSiniflari/psikiyatrist.h \
    Veri/VeriSiniflari/sonuc.h \
    Veri/VeriSiniflari/tedaviyontemi.h \
    Veri/VeriSiniflari/temversinifi.h \
    Veri/VeriSiniflari/ziyaret.h \
    Veri/data.h \
    soyesilay.h

FORMS += \
    Formlar/ListeFormlari/birimlisteformu.ui \
    Formlar/VeriFormlari/birimverigirisi.ui \
    Formlar/VeriFormlari/gozetmenverigirisi.ui \
    Formlar/VeriFormlari/hastaverigirisi.ui \
    Formlar/VeriFormlari/psikiyatrverigirisi.ui \
    soyesilay.ui

TRANSLATIONS += \
    YesilayYBS_tr_TR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Kaynaklar.qrc
