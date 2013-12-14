#include "IdGenerator.h"

int IdGenerator::s_id = 0;

int IdGenerator::next()
{
	return s_id++;
}
