#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "HCTree.hpp"

int main(int argc, char* argv[])
{
	// read the file into a buffer
	std::ifstream ifs(argv[1], std::ios::binary);
	std::vector<char> buffer((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));


	// count the occurences of each char
	std::vector<int> freqs(256, 0);
	for (size_t i = 0; i < buffer.size(); ++i) {
		char c = buffer[i];
		++freqs[c];
	}

	HCTree hct;
	hct.build(freqs);

	return 0;
}
