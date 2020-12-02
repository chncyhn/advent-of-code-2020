#include <iostream>
#include <fstream>
#include <set>
#include <vector>

int main(int, char**) {
	std::fstream myfile("data1.txt", std::ios_base::in);
	std::set<int> vals_set;
	std::vector<int> vals;
	int inp;
	while (myfile >> inp) {
		vals_set.insert(inp);
		vals.push_back(inp);
	}
	for (int i=0; i < vals.size(); i++) {
		for (int j=i+1; j < vals.size(); j++) {
			int complement = 2020 - vals[i] - vals[j];
			if (vals_set.find(complement) != vals_set.end()) {
				std::cout << "Values are " << vals[i] << " " << vals[j] << " " << complement << std::endl;
				std::cout << "Result: " << vals[i] * vals[j] * complement << std::endl;
				return 0;
			}
		}
	}	
	return 1;
}
