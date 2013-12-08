#ifndef BINARYSTREAM_H
#define BINARYSTREAM_H

#include <fstream>

class BinaryStream
{
	public:
		BinaryStream(std::fstream &subject);

	private:
		friend BinaryStream &operator >>(BinaryStream &stream, int &value);
		friend BinaryStream &operator <<(BinaryStream &stream, const int &value);

		std::fstream &m_subject;
};

#endif // BINARYSTREAM_H
