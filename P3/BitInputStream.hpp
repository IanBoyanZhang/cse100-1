#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class BitInputStream
{
	public:
		BitInputStream(std::istream &in);

		std::vector<std::bitset<8> > bits;
		std::string header;
		static std::vector<int> getFrequency();

	private:
		std::istream &in;
};

