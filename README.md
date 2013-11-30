# Ludum Dare #28 (Jam)

## Key features

We have already defined some key features that we would like in our finished game.

### Planned
- Pseudo-random level creation using rooms created in Tiled
- AI with pathfinding (probably using A*)
- Local 2-player co-op (using kbd/mouse and gamepad)
- Physics engine so that we can do fancy stuff like explosions with pushback effect
- Gamepad support
- Cross-platform supporting Linux, Windows and hopefully Mac OS X

### Completed
- Tile-based map loading (.tmx files created using Tiled)

## Why we have started before the compo

We have already decided that we're doing a tile-based top-down game this compo, since we usually do side-scrollers. So we thought that we should start ahead to get the engine up and running. We've planned to have most of the features listed above finished before the compo starts, which would allow us to work 100% on game design and implementation during the actual compo. This will hopefully lead to a more polished and less buggy game than our previous entries where we would pretty much write the entire engine during the compo.

This code is licensed under GPLv2 and anyone is free to fork this and use for their own games if they like. We will also announce that we're using this as a base in our pre-compo blog post at ludumdare.com a few days before the compo starts.

## Compiling the source

We're using the following libraries:
- SFML 2.1
- Box2D 2.3.0
- tmx-parser (http://code.google.com/p/tmx-parser/)

During development we're using qmake since this integrates better with our IDE (Qt Creator), but for the final "release" we will switch to cmake so that Qt isn't required.

### Linux (qmake during development)

    cd src/
    qmake -config release
    make
