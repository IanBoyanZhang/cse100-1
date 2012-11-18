#include <iostream>
#include <string>

class BitOutputStream
{
	public:
		BitOutputStream(std::ostream &out);
		~BitOutputStream();

		void writeBit(bool bit);
		void flush();

		std::ostream &out;

	private:
		int count;
		char byte;
};
