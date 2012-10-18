#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "HCTree.hpp"

void makeHeader(HCTree hct, std::vector<int> freqs, std::ostream &os)
{
	os << "# HCT" << std::endl;
	for (size_t i = 0; i < freqs.size(); ++i) {
		if (freqs[i]) {
			BitOutputStream bs(os);
			hct.encode(i, bs);
			bs.output(freqs[i]);
		}
	}
	os << std::endl << "# END" << std::endl;
}

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
	makeHeader(hct, freqs, std::cout);

	return 0;
}
