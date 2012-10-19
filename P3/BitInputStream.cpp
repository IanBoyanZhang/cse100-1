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
		bits.push_back(std::bitset<8>(buffer[i]));
	}
}
