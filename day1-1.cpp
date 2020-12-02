#include <iostream>
#include <fstream>
#include <set>

int main(int, char**) {
	std::set<int> seen;
	
	std::fstream myfile("data1.txt", std::ios_base::in);
	int i;
	while (myfile >> i) {
		int complement = 2020 - i;
		if (seen.find(complement) != seen.end()) {
			std::cout << "Values are " << i << " and " << complement << std::endl;
			std::cout << "Result: " << i * complement << std::endl;
		}
		seen.insert(i);
	}
	return 0;
}
