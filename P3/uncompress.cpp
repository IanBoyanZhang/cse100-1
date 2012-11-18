#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HCTree.hpp"

// get the size of the compressed file in bits
int getSize(HCTree hct, std::vector<int> freqs)
{
	int result = 0;
	for (size_t i = 0; i < freqs.size(); ++i) {
		if (freqs[i]) {
			result += freqs[i] * hct.getCode(i).size(); 
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	// read the file into a buffer
	std::ifstream ifs(argv[1], std::ios::binary);
	std::string buffer((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));

	// create a BitInputStream
	std::stringstream ss(buffer);
	BitInputStream bis(ss);

	// build the tree
	HCTree hct;
	hct.build(bis.freqs);

	bis.size = getSize(hct, bis.freqs);

	std::ofstream ofs(argv[2], std::ios::binary);

	int c = hct.decode(bis);
	while (c >= 0) {
		ofs << (char)c;
		c = hct.decode(bis);
	}

	return 0;
}
