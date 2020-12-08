#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int f(std::string ticket) {
	int xLo=0, xHi=127, yLo=0, yHi=7;
	for (int i=0; i<ticket.size(); i++) {
		if (ticket[i] == 'F') xHi = (xLo + xHi - 1) / 2;
		else if (ticket[i] == 'B') xLo = (xLo + xHi - 1) / 2 + 1;
		else if (ticket[i] == 'L') yHi = (yLo + yHi - 1) / 2;
		else yLo = (yLo + yHi - 1) / 2 + 1;
	}
	return 8 * xLo + yLo;
}

int main(int, char**) {
	std::fstream myfile("data5.txt", std::ios_base::in);
	std::vector<std::string> tickets;
	std::string ticket;
	while (myfile >> ticket) {
		tickets.push_back(ticket);
	}

	int pt1, pt2;
	std::vector<int> ids;
	for (auto t : tickets) {
		int id = f(t);
		pt1 = std::max(pt1, id);
		ids.push_back(id);
	}
	std::sort(ids.begin(), ids.end());
	for (int i=0; i<ids.size()-1; i++) { 
		if (ids[i+1] - ids[i] > 1) {
			pt2 = ids[i] + 1;
			break;
		}
	}	
	std::cout << "Part 1: " << pt1 << std::endl;
	std::cout << "Part 2: " << pt2 << std::endl;
	return 0;
}
