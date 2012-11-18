#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class BitInputStream
{
	public:
		BitInputStream(std::istream &in);


		// get the next bit in the stream
		int next();

		// for debugging, print the header used to decompress the file
		void print();

		bool good;
		int size;
		std::vector<int> freqs;

	private:
		// parse the header for the character frequencies
		void getFreqs();

		// read the header used in compressed files
		void readHeader();

		// read a string into the bits vector
		void readBuffer(std::string buffer);

		int index;
		std::vector<bool> bits;
		std::string header;
		std::istream &in;
};
