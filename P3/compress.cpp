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
	std::map<char, int> counts;
	for (size_t i = 0; i < buffer.size(); ++i) {
		counts.insert(std::pair<char, int>(buffer[i], 0));
		++counts[buffer[i]];
	}

	std::vector<int> freqs;
	std::map<char, int>::iterator it;
	for (it = counts.begin(); it != counts.end(); ++it) {
		//std::cout << (*it).first << ": " << (*it).second << std::endl;
		freqs[(*it).first] = (*it).second;
	}

	HCTree hct;
	hct.build(freqs);

	return 0;
}
