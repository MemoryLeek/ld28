#ifndef DAMAGABLE_H
#define DAMAGABLE_H

class Damagable
{
	public:
		Damagable(int health);

		bool isDead() const;
		int remainingHealth() const;
		int maxHealth() const;
		void doDamage(int damage);

	private:
		int m_health;
		const int m_maxHealth;
};

#endif // DAMAGABLE_H
