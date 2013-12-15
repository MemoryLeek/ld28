#ifndef HUMANOIDBOT_H
#define HUMANOIDBOT_H

#include <Box2D/Common/b2Math.h>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "Bot.h"

class HumanoidBot : public Bot
{
	public:
		HumanoidBot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder, const sf::SoundBuffer &stepSound, Map &map);

		void onUpdate(int delta) override;
		void onTargetSpotted(const WorldObject *target) override;
		void onTargetNoLongerVisible(const WorldObject *target) override;
		void onTargetHeard(const WorldObject *target) override;
		void onPathEnd() override;

	private:
		const WorldObject *m_target;

		sf::Sound m_stepSound;
		int m_stepTimer;

		int m_fireTimer;
};

#endif // HUMANOIDBOT_H
