#include "BitInputStream.hpp"

BitInputStream::BitInputStream(std::istream &in) : in(in), header()
{
	std::string line;
	std::getline(in, line);
	if (line != "# HCT") {
		std::cout << "!!! This is not a compressed file !!!" << std::endl;
	}
	std::getline(in, line);
	header = line;
	while (line != "# END") {
		header += "\n" + line;
	}
	std::string buffer;
	std::getline(in, buffer);
	for (size_t i = 0; i < buffer.size(); ++i) {
		for (int j = 7; j >= 0; --j) {
			if ((buffer[i] >> j) & 1) {
				bits.push_back(true);
			} else {
				bool.push_back(false);
			}
		}
	}
}

std::vector<int> BitInputStream::getFrequncies()
{
	std::stringstream ss(header);
	std::string key;
	key << ss;
}
