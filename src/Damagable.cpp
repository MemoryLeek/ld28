#include "Damagable.h"

Damagable::Damagable(int health)
	: m_health(health)
	, m_maxHealth(health)
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

int Damagable::maxHealth() const
{
	return m_maxHealth;
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
