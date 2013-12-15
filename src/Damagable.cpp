#include "Damagable.h"

Damagable::Damagable(int health)
	: m_health(health)
{
}

bool Damagable::isDead() const
{
	return m_health == 0;
}

int Damagable::remainingHealth() const
{
	return m_health;
}

void Damagable::doDamage(int damage)
{
	if(damage > m_health)
	{
		m_health = 0;
	}
	else
	{
		m_health -= damage;
	}
}
