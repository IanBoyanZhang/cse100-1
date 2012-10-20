#include <sstream>
#include "BitInputStream.hpp"

bool BitInputStream::good()
{
	return !error;
}

bool BitInputStream::next()
{
	bool result = bits[position];
	++position;
	if (position >= bits.size()) {
		error = true;
	}
	return result;
}

BitInputStream::BitInputStream(std::istream &in) : in(in), position(0), header(), error(false)
{
	std::string line;
	std::getline(in, line);
	if (line != "# HCT") {
		std::cout << "!!! This is not a compressed file !!!" << std::endl;
	}
	std::getline(in, line);
	header = line;
	std::getline(in, line);
	while (line != "# END") {
		header += "\n" + line;
		std::getline(in, line);
	}
	std::string buffer;
	std::getline(in, line);
	buffer = line;
	while (in.good()) {
		buffer += "\n" + line;
		std::getline(in, line);
	}
	for (size_t i = 0; i < buffer.size(); ++i) {
		for (int j = 7; j >= 0; --j) {
			if ((buffer[i] >> j) & 1) {
				bits.push_back(true);
			} else {
				bits.push_back(false);
			}
		}
	}
	std::cout << "HEADER: " << header << std::endl;
	std::cout << "BUFFER: " << buffer << std::endl;
	std::cout << "BITS: ";
	for (size_t i = 0; i < bits.size(); ++i) {
		std::cout << bits[i];
	}
	std::cout << std::endl;
	std::cout << "SIZE: " <<  bits.size() << std::endl;
}

std::vector<int> BitInputStream::getFreqs()
{
	std::vector<int> result(256, 0);

	std::stringstream ss(header);
	while (!ss.eof()) {
		std::string key;
		ss >> key;
		char c = key[0];
		if (!c) {
			break;
		}

		std::stringstream ss2(key.substr(1));
		int frequency;
		ss2 >> frequency;

		result[c] = frequency;
	}

	return result;
}
