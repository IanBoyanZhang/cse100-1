#include <iostream>
#include <string>

class BitOutputStream
{
	public:
		BitOutputStream(std::ostream &out);
		~BitOutputStream();

		// pack a single bit into the byte
		void writeBit(bool bit);

		// send the byte to the stream
		void flush();

		std::ostream &out;

	private:
		int count;
		char byte;
};
