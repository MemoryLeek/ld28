#ifndef HUMANOIDBOT_H
#define HUMANOIDBOT_H

#include <Box2D/Common/b2Math.h>

#include "Bot.h"

class HumanoidBot : public Bot
{
	public:
		HumanoidBot(WorldPosition *position, const std::list<const WorldObject *> &enemies, const Pathfinder *pathfinder);

		void onTargetSpotted(const WorldObject *target) override;
		void onTargetHeard(const WorldObject *target) override;
		void onPathEnd() override;

	private:
		const WorldObject *m_target;
};

#endif // HUMANOIDBOT_H
