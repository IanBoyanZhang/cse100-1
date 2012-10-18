#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HCTree.hpp"

int main(int argc, char* argv[])
{
	// read the file into a buffer
	std::ifstream ifs(argv[1], std::ios::binary);
	std::string buffer((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));

	// make a BitInputStream from the file
	std::stringstream ss(buffer);
	BitInputStream bis(ss);

	// count the occurences of each char
	std::vector<int> freqs(256, 0);
	for (size_t i = 0; i < bis.header.size(); ++i) {
		char c = bis.header[i];
		++freqs[c];
	}

	HCTree hct;
	hct.build(freqs);

	return 0;
}
