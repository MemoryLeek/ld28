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

void Damagable::giveHealth(int health)
{
	if(m_health + health > m_maxHealth)
	{
		m_health = m_maxHealth;
	}
	else
	{
		m_health += health;
	}
}
