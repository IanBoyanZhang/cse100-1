#include "BitOutputStream.hpp"

void BitOutputStream::writeBit(bool bit)
{
	if (count >= 8) {
		flush();
	}
	++count;

	if (bit) {
		byte = (byte << 1) | 1;
	} else {
		byte = (byte << 1);
	}
}

void BitOutputStream::flush()
{
	buffer += byte;
	count = 0;
	byte ^= byte;	// zero the byte
}

void BitOutputStream::output()
{
	byte = byte << (8 - count);
	flush();
	out << buffer << " ";
}
