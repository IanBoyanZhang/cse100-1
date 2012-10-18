#include <iostream>
#include <string>

class BitOutputStream
{
	public:
		BitOutputStream(std::ostream &out) : out(out), count(0), byte(0)
		{
			buffer = "";
			byte = 'a';
			byte ^= byte;	// zero the byte
		}

		void writeBit(bool bit);
		void output(char symbol);

	private:
		void flush();

		int count;
		char byte;
		std::string buffer;
		std::ostream &out;
};
