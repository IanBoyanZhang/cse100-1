# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-g
LDFLAGS=-g

all: compress uncompress

compress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

uncompress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

HCTree.o: BitInputStream.hpp BitOutputStream.hpp HCNode.hpp HCTree.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

clean:
	rm -f compress uncompress *.o core*

purify:
	prep purify
	purify -cache-dir=$HOME g++ compress.cpp BitOutputStream.cpp BitInputStream.cpp HCTree.cpp HCNode.cpp -o compress

	purify -cache-dir=$HOME g++ uncompress.cpp BitOutputStream.cpp BitInputStream.cpp HCTree.cpp HCNode.cpp -o uncompress

test: compress uncompress
	./compress input_files/justA output_files/justA
	./compress input_files/lotsofA output_files/lotsofA
	./compress input_files/justABC output_files/justABC
	./compress input_files/empty output_files/empty
	./compress input_files/binary.dat output_files/binary.dat
	./compress input_files/warandpeace.txt output_files/warandpeace.txt
	./compress input_files/kamasutra.txt output_files/kamasutra.txt
	./uncompress output_files/justABC output_files/justABC.in
	./uncompress output_files/lotsofA output_files/lotsofA.in
	./uncompress output_files/justA output_files/justA.in
	./uncompress output_files/empty output_files/empty.in
	./uncompress output_files/binary.dat output_files/binary.dat.in
	./uncompress output_files/warandpeace.txt output_files/warandpeace.txt.in
	./uncompress output_files/kamasutra.txt output_files/kamasutra.txt.in
	diff input_files/justABC output_files/justABC.in
	diff input_files/lotsofA output_files/lotsofA.in
	diff input_files/justA output_files/justA.in
	diff input_files/empty output_files/empty.in
	diff input_files/binary.dat output_files/binary.dat.in
	diff input_files/warandpeace.txt output_files/warandpeace.txt.in
	diff input_files/kamasutra.txt output_files/kamasutra.txt.in
	./refcompress input_files/justA ref_files/justA
	./refcompress input_files/lotsofA ref_files/lotsofA
	./refcompress input_files/justABC ref_files/justABC
	./refcompress input_files/empty ref_files/empty
	./refcompress input_files/binary.dat ref_files/binary.dat
	./refcompress input_files/warandpeace.txt ref_files/warandpeace.txt
	./refcompress input_files/kamasutra.txt ref_files/kamasutra.txt
	ls -l input_files/ output_files/ ref_files/
