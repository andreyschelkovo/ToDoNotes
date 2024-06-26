QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    books_from_where_form.cpp \
    books_wishlist_reason_text.cpp \
    deleted_description_form.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    books_from_where_form.h \
    books_wishlist_reason_text.h \
    deleted_description_form.h \
    mainwindow.h

FORMS += \
    books_from_where_form.ui \
    books_wishlist_reason_text.ui \
    deleted_description_form.ui \
    mainwindow.ui


win32:RC_FILE = file_ico.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
