#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class BitInputStream
{
	public:
		BitInputStream(std::istream &in) : in(in), header()
		{
			std::string line;
			std::getline(in, line);
			if (line != "# HCT") {
				std::cout << "This is not a compressed file" << std::endl;
			}
			while (line != "# END") {
				std::getline(in, line);
				header += line;
			}
			std::string buffer;
			std::getline(in, buffer);
			for (size_t i = 0; i < buffer.size(); ++i) {
				bits.push_back(std::bitset<8>(buffer[i]));
			}
		}

		std::vector<std::bitset<8> > bits;
		std::string header;

	private:
		std::istream &in;
};
