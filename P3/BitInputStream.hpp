#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class BitInputStream
{
	public:
		BitInputStream(std::istream &in);

		bool nextBit();
		std::vector<int> getFrequncies();

		std::vector<bool> bits;

	private:
		std::string header;
		std::istream &in;
};

