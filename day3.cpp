#include <iostream>
#include <fstream>
#include <vector>

int main(int, char**) {
	std::fstream myfile("data3.txt", std::ios_base::in);
	std::vector<std::string> rows;
	std::string row;
	while (myfile >> row) {
		rows.push_back(row);
	}

	std::vector<std::pair<int, int>> slopes = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
	int vlen = rows.size(), hlen = rows[0].size();
	int ret = 1;
	for (auto slope : slopes) {
		int x = 0, y = 0, cur = 0;
		while (y < vlen) {
			cur += (rows[y].at(x) == '#');
			x = (x + slope.first) % hlen;
			y += slope.second;
		}
		ret *= cur;
	}
	std::cout << ret << std::endl;
	return 0;
}
