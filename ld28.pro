CONFIG -= qt

TARGET = ld28
DESTDIR = bin

OBJECTS_DIR = build

LIBS += -lsfml-system -lsfml-graphics -lsfml-window

SOURCES += \
    main.cpp \
    MapObject.cpp \
    CollidableObject.cpp

HEADERS += \
    MapObject.h \
    CollidableObject.h
