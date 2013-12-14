CONFIG += C++11

SOURCES += \
    main.cpp \
    QStringEx.cpp \
    TileObject.cpp \
    RoomLoader.cpp \
    RoomObject.cpp \
    RoomLookup.cpp \
    RoomLookupPersister.cpp \
    DirectionSelectorStrategy.cpp

HEADERS += QStringEx.h \
    TileObject.h \
    RoomLoader.h \
    RoomObject.h \
    RoomLookup.h \
    RoomLookupPersister.h \
    TileFeature.h \
    Direction.h \
    DirectionSelectorStrategy.h \
    PropertyEnumMapper.h \
    MapType.h

LIBS += -ltiled
