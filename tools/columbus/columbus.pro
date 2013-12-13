CONFIG += C++11

SOURCES += \
    main.cpp \
    QStringEx.cpp \
    TileObject.cpp \
    RoomLoader.cpp \
    RoomObject.cpp \
    RoomLookup.cpp \
    RoomLookupPersister.cpp

HEADERS += QStringEx.h \
    TileObject.h \
    RoomLoader.h \
    RoomObject.h \
    RoomLookup.h \
    RoomLookupPersister.h

LIBS += -ltiled
