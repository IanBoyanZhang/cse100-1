#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "HCTree.hpp"

// creates the header used to rebuild the tree with the following format:
/*
	char freq char freq ... char freq
*/
void makeHeader(std::ostream &out, std::vector<int> freqs)
{
	for (size_t i = 0; i < freqs.size(); ++i) {
		if (freqs[i]) {
			out << i << " " << freqs[i] << " ";
		}
	}
	out << std::endl;
}

int main(int argc, char* argv[])
{
	// read the file into a buffer
	std::ifstream ifs(argv[1], std::ios::binary);
	std::string buffer((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));

	// create a new file if we're trying to comrpess an empty file
	if (!buffer.size()) {
		std::ofstream ofs(argv[2], std::ios::binary);
		exit(0);
	}

	// count the occurences of each char
	std::vector<int> freqs(256, 0);
	for (size_t i = 0; i < buffer.size(); ++i) {
		byte b = buffer[i];
		++freqs[b];
	}

	// build the HCTree
	HCTree hct;
	hct.build(freqs);

	// output the compressed file
	std::ofstream ofs(argv[2], std::ios::binary);
	BitOutputStream bos(ofs);
	makeHeader(ofs, freqs);
	for (size_t i = 0; i < buffer.size(); ++i) {
		hct.encode(buffer[i], bos);
	}

	return 0;
}
