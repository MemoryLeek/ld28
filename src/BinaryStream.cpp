#include "BinaryStream.h"

BinaryStream::BinaryStream(std::fstream &subject)
	: m_subject(subject)
{

}

BinaryStream &operator >>(BinaryStream &stream, int &value)
{
	std::fstream &subject = stream.m_subject;
	subject.read((char *)&value, sizeof(int));

	return stream;
}

BinaryStream &operator <<(BinaryStream &stream, const int &value)
{
	std::fstream &subject = stream.m_subject;
	subject.write((char *)&value, sizeof(int));

	return stream;
}
