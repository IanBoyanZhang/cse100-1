#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class BitInputStream
{
	public:
		BitInputStream(std::istream &in);

		bool next();
		bool good();
		std::vector<int> getFreqs();


	private:
		int position;
		bool error;
		std::vector<bool> bits;
		std::string header;
		std::istream &in;
};

