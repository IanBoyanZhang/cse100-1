#include <sstream>
#include "BitInputStream.hpp"

int BitInputStream::peek()
{
	if (position + 1 <= bits.size()) {
		return bits[position + 1];
	} else {
		return -1;
	}
}

bool BitInputStream::next()
{
	bool result = bits[position++];
	if (position >= bits.size()) {
		good = false;
	}
	return result;
}

BitInputStream::BitInputStream(std::istream &in) : in(in), position(0), header(), good(true)
{
	std::string line;

	std::getline(in, line);
	if (line != "# HCT") {
		std::cout << "!!! This is not a compressed file !!!" << std::endl;
	}

	std::getline(in, header);

	std::getline(in, line);
	if (line != "# END") {
		std::cout << "!!! This is not a compressed file !!!" << std::endl;
	}

	std::string buffer((std::istreambuf_iterator<char>(in)),
			(std::istreambuf_iterator<char>()));

	for (size_t i = 0; i < buffer.size(); ++i) {
		for (int j = 7; j >= 0; --j) {
			if ((buffer[i] >> j) & 1) {
				bits.push_back(true);
			} else {
				bits.push_back(false);
			}
		}
	}
	/*
	std::cout << "HEADER: " << header << std::endl;
	std::cout << "BUFFER: " << buffer << std::endl;
	std::cout << "BITS: ";
	for (size_t i = 0; i < bits.size(); ++i) {
		std::cout << bits[i];
	}
	std::cout << std::endl;
	std::cout << "SIZE: " <<  bits.size() << std::endl;
	*/
}

std::vector<int> BitInputStream::getFreqs()
{
	std::vector<int> result(256, 0);

	std::stringstream ss(header);
	while (!ss.eof()) {
		int key, frequency;
		ss >> key >> frequency;
		result[key] = frequency;
	}

	return result;
}
