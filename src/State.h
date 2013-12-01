#ifndef STATE_H
#define STATE_H

class InputMapping;

class State
{
	public:
		virtual void setupInput(InputMapping *mapping) = 0;
		virtual void update() = 0;
};

#endif // STATE_H
