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
	std::vector<int> freqs = bis.getFreqs();

	HCTree hct;
	hct.build(freqs);

	std::ofstream ofs(argv[2], std::ios::binary);
	while (bis.good()) {
		ofs << (char)hct.decode(bis);
	}

	return 0;
}
