#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "RST.hpp"
#include "BST.hpp"
#include "countint.hpp"

// creates and populates the appropriate data structure
// returns the avg number of comparisons for a single run
double single(int n, bool sorted, std::string type)
{
	std::vector<countint> v;
	for (int i = 0; i < n; ++i) {
		v.push_back(i);
	}

	if (!sorted) {
		std::random_shuffle(v.begin(), v.end());
	}

	/*
	std::cout << std::endl;
	std::cout << "INSERTING VALUES: " << std::endl;

	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
		std::cout << std::endl;
	}
	*/

	// lots of copy and pasting here because of scoping issues
	if (type == "set") {
		std::set<countint> t;
		for (size_t i = 0; i < v.size(); ++i) {
			t.insert(v[i]);
		}
		countint::clearcount();
		for (size_t i = 0; i < v.size(); ++i) {
			t.find(v[i]);
		}
	} else if (type == "bst") {
		BST<countint> t;
		for (size_t i = 0; i < v.size(); ++i) {
			t.insert(v[i]);
		}
		countint::clearcount();
		for (size_t i = 0; i < v.size(); ++i) {
			t.find(v[i]);
		}
	} else {
		RST<countint> t;
		for (size_t i = 0; i < v.size(); ++i) {
			t.insert(v[i]);
		}
		countint::clearcount();
		for (size_t i = 0; i < v.size(); ++i) {
			t.find(v[i]);
		}
	}

	return countint::getcount() / (double)n;
}

// averages the results of benchmark over several runs
// returns the avg, stdev is modified by reference
void benchmark(int n, bool sorted, std::string type, int runs, double &avg, double &stdev)
{
	double sum = 0.0, squares = 0.0;
	for (int i = 0; i < runs; ++i) {
		double result = single(n, sorted, type);
		sum += result;
		squares += result * result;
	}
	avg = sum / runs;
	double avgsquares = squares / (double)runs;
	stdev = sqrt(abs(avgsquares - (avg * avg)));
}


int main(int argc, char *argv[])
{
	// command line parsing
	std::string type(argv[1]);
	std::string data(argv[2]);
	bool sorted = true ? data == "sorted" : false;
	std::stringstream ss(std::string(argv[3]) + " " +  std::string(argv[4]));
	int N, runs;
	ss >> N >> runs;


	// comment output
	std::cout << "# Data Structure: " << type << std::endl;
	std::cout << "# Data: " << data << std::endl;
	std::cout << "# N: " << N << std::endl;
	std::cout << "# runs: " << runs << std::endl;
	std::cout << "# N\tavgcomps\tstdev" << std::endl;

	// main loop
	int i = 1, n = 1;
	double avg = 0.0, stdev = 0.0;
	while (n <= N) {
		std::cout << n << "\t";
		benchmark(n, sorted, type, runs, avg, stdev);
		std::cout << avg << "\t\t" << stdev << std::endl;
		n += (int)pow(2, i);
		++i;
	}
	/*
	*/

	return 0;
}
