#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IdGenerator
{
	public:
		static int next();

	private:
		static int s_id;
};

#endif // IDGENERATOR_H
