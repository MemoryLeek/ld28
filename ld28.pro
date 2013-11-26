CONFIG -= qt

TARGET = ld28
DESTDIR = bin

OBJECTS_DIR = build

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lBox2D -ltmxparser -ltinyxml -lz
CONFIG += c++11

SOURCES += \
    main.cpp \
    CollidableObject.cpp \
	World.cpp \
    MapLoader.cpp \
    DrawableObject.cpp \
    Map.cpp \
    TileObject.cpp \
    WorldObject.cpp \
    WorldDebug.cpp

HEADERS += \
    CollidableObject.h \
	World.h \
    MapLoader.h \
    DrawableObject.h \
    Map.h \
    StringEx.h \
    TileObject.h \
    WorldObject.h \
    WorldDebug.h
