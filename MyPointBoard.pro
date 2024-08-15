QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractShapeItem.cpp \
    AtomPointItem.cpp \
    CenterAndEdgePointItem.cpp \
    CircleItem.cpp \
    EllipseItem.cpp \
    RectangleItem.cpp \
    SquareItem.cpp \
    main.cpp \
    MyPaintBoard.cpp

HEADERS += \
    AbstractShapeItem.h \
    AtomPointItem.h \
    CenterAndEdgePointItem.h \
    CircleItem.h \
    EllipseItem.h \
    MyPaintBoard.h \
    RectangleItem.h \
    SquareItem.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
