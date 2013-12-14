#ifndef PLAYERINPUTPROXY_H
#define PLAYERINPUTPROXY_H

class Player;

class PlayerInputProxy
{
	public:
		PlayerInputProxy(Player *player);

		void absoluteInput(const float x, const float y);
		void relativeInput(const float x, const float y);

		void moveLeft();
		void moveRight();
		void moveForward();
		void moveBackwards();

		void interact();

		void stopHorizontally();
		void stopVertically();

		void nothing();

	private:
		Player *m_player;
};

#endif // PLAYERINPUTPROXY_H
