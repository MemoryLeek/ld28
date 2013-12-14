#include "RayCastResult.h"

RayCastResult::RayCastResult()
{
}


float32 RayCastResult::ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float32 fraction)
{
	if(fixture->IsSensor())
	{
		return -1;
	}

	m_fixture = fixture;
	m_point = point;
	m_normal = normal;
	m_fraction = fraction;

	return fraction;
}

b2Fixture *RayCastResult::fixture() const
{
	return m_fixture;
}
