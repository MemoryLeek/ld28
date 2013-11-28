CONFIG -= qt

TARGET = ld28
DESTDIR = ../bin

OBJECTS_DIR = build

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lBox2D -ltmxparser -ltinyxml -lz
CONFIG += c++11

SOURCES += \
    main.cpp \
	World.cpp \
    MapLoader.cpp \
    DrawableObject.cpp \
    Map.cpp \
    TileObject.cpp \
    WorldObject.cpp \
    WorldDebug.cpp \
    TileLayer.cpp \
    RenderProxy.cpp \
    StaticWorldPosition.cpp \
    PhysicsWorldPosition.cpp \
    Player.cpp \
    PositionFactory.cpp

HEADERS += \
	World.h \
    MapLoader.h \
    DrawableObject.h \
    Map.h \
    StringEx.h \
    TileObject.h \
    WorldObject.h \
    WorldDebug.h \
    TileLayer.h \
    RenderProxy.h \
    WorldPosition.h \
    StaticWorldPosition.h \
    PhysicsWorldPosition.h \
    Player.h \
    PositionFactory.h
