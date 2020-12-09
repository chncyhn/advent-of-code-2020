#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int, char**) {
	std::ifstream fd("data6.txt");
	int p1 = 0, p2 = 0, cnt = 0;
	int cur[26] = {0};
	std::string row;
	while (getline(fd, row)) {
		if (row.size() == 0) {
			for (int i=0; i<26; i++) 
				p2 += cur[i] == cnt;
			std::fill(cur, cur+26, 0);
			cnt = 0;
		} else {
			cnt++;
			for (int i=0; i<row.size(); i++) 
				if (cur[row[i]-'a']++ == 0)
					p1++;
		}
	}
	for (int i=0; i<26; i++) 
		p2 += cur[i] == cnt;
	std::cout << "Part 1: " << p1 << std::endl;
	std::cout << "Part 2: " << p2 << std::endl;
	return 0;
}
