#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class BitInputStream
{
	public:
		BitInputStream(std::istream &in);

		bool next();
		int peek();

		bool good;

		// parse the header for the character frequencies
		std::vector<int> getFreqs();

	private:
		int position;
		std::vector<bool> bits;
		std::string header;
		std::istream &in;
};

