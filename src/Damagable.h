#ifndef DAMAGABLE_H
#define DAMAGABLE_H

class Damagable
{
	public:
		Damagable(int health);

		bool isDead() const;
		int remainingHealth() const;
		void doDamage(int damage);

	private:
		int m_health;
};

#endif // DAMAGABLE_H
