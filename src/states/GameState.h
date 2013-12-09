#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.h"

class Bot;
class Map;
class Player;
class World;
class PlayerInputProxy;
class Pathfinder;

const float TIMESTEP = 1.f / 120.f;

class GameState : public State
{
	public:
		GameState(sf::RenderWindow *window);

		void setupInput(InputMapping *mapping) override;
		void update() override;

	private:
		bool shouldStep();

		sf::RenderWindow *m_window;
		sf::Clock m_clock;
		sf::Clock m_fpsTimer;
		sf::Text m_fpsText;
		sf::Font m_font;

		World *m_world;
		Bot *m_bot;
		Map *m_map;
		Player *m_player;
		PlayerInputProxy *m_proxy;
		Pathfinder *m_pathfinder;

		int m_lastPhysicsStepTime;
		int m_fpsCount;
};

#endif // GAMESTATE_H
