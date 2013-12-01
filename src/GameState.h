#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class Player;
class World;
class PlayerInputProxy;

class GameState : public State
{
	public:
		GameState();

		void setupInput(InputMapping *mapping) override;
		void update() override;

	private:
		World *m_world;
		Player *m_player;
		PlayerInputProxy *m_proxy;
};

#endif // GAMESTATE_H
