#include "BitOutputStream.hpp"

BitOutputStream::BitOutputStream(std::ostream &out) : out(out), byte(0), count(0)
{
}

BitOutputStream::~BitOutputStream()
{
	if (count) {
		flush();
	}
}

void BitOutputStream::writeBit(bool bit)
{
	++count;

	if (bit) {
		byte = (byte << 1) | 1;
	} else {
		byte = (byte << 1);
	}

	if (count >= 8) {
		flush();
	}
}

void BitOutputStream::flush()
{
	byte = byte << (8 - count);
	count = 0;
	out << byte;
	byte ^= byte;	// zero the byte
}
