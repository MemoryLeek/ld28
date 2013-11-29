#ifndef RAYCASTRESULT_H
#define RAYCASTRESULT_H

#include <Box2D/Common/b2Math.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2WorldCallbacks.h>

class RayCastResult : public b2RayCastCallback
{
	public:
		RayCastResult();

		float32 ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float32 fraction) override;

		b2Fixture *fixture() const;

	private:
		b2Fixture *m_fixture;
		b2Vec2 m_point;
		b2Vec2 m_normal;
		float m_fraction;
};

#endif // RAYCASTRESULT_H
