# Ludum Dare #28 (Jam)

## Key features

We have already defined some key features that we would like in our finished game.

### Planned
- Pseudo-random level creation using rooms created in Tiled
- AI with pathfinding (probably A*)
- Local 2-player co-op (using kbd/mouse and gamepad)
- Physics engine so that we can do fancy stuff like explosions with pushback effect
- Gamepad support
- Cross-platform supporting Linux, Windows and hopefully Mac OS X

### Completed
- Tile-based map loading (.tmx files created using Tiled)

## Why we have started before the compo

We have already decided that we're doing a tile-based top-down game this compo, since we usually do side-scrollers. This allows us to start working before the theme is announced, the artwork and gameplay will most likely be created/defined during the actual compo. All code in this repo is licensed under GPLv2 so that others are allowed to use/fork our code if they want to for some reason, we will also link to this repo in the ludumdare.com blog post that we'll post before the compo starts.

## Compiling the source

We're using the following libraries:
- SFML 2.1
- Box2D 2.3.0
- tmx-parser (http://code.google.com/p/tmx-parser/)

During development we're using qmake since this integrates better with our IDE (Qt Creator), but for the final "release" we will switch to cmake so that Qt isn't required.

### Linux (qmake during development)

    qmake -config release
    make
