#include <sstream>
#include "BitInputStream.hpp"

BitInputStream::BitInputStream(std::istream &in) : in(in), index(0), header(), good(true), size(0)
{
	std::string line;
	std::getline(in, line);
	if (line != "# HCT") {
		std::cout << "!!! This is not a compressed file !!!" << std::endl;
	}

	std::getline(in, header);

	std::getline(in, line);
	// # END

	std::string buffer((std::istreambuf_iterator<char>(in)),
			(std::istreambuf_iterator<char>()));

	freqs = std::vector<int>(256, 0);
	getFreqs();
	readBuffer(buffer);
}

void BitInputStream::readBuffer(std::string buffer)
{
	for (size_t i = 0; i < buffer.size(); ++i) {
		for (int j = 7; j >= 0; --j) {
			if ((buffer[i] >> j) & 1) {
				bits.push_back(true);
			} else {
				bits.push_back(false);
			}
		}
	}
}

void BitInputStream::print()
{
	std::cout << "HEADER: " << header << std::endl;
	std::cout << "BITS: ";
	for (size_t i = 0; i < bits.size(); ++i) {
		std::cout << bits[i];
		if ((i + 1) % 8 == 0) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

int BitInputStream::next()
{
	if (index >= size) {
		return -1;
	}
	return bits[index++];
}

void BitInputStream::getFreqs()
{
	std::stringstream ss(header);
	while (!ss.eof()) {
		int key, frequency;
		ss >> key >> frequency;
		freqs[key] = frequency;
	}
}
