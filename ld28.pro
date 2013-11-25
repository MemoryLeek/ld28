CONFIG -= qt

TARGET = ld28
DESTDIR = bin

OBJECTS_DIR = build

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lBox2D

SOURCES += \
    main.cpp \
    MapObject.cpp \
    CollidableObject.cpp \
    World.cpp

HEADERS += \
    MapObject.h \
    CollidableObject.h \
    World.h
