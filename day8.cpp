#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

std::vector<std::pair<int, int>> read_opvals() {
	std::ifstream fd("data8.txt");
	std::string inp;
	std::vector<std::pair<int, int>> opvals;
	// NOP 0, ACC 1, JMP 2
	while (getline(fd, inp)) {
		int delim = inp.find(" ");
		std::string op = inp.substr(0, delim);
		int opnum = op.compare("nop") == 0 ? 0 : (op.compare("acc") == 0 ? 1 : 2);
		int val = std::stoi(inp.substr(delim+1, inp.size()));
		opvals.push_back(std::make_pair(opnum, val));
	}
	return opvals;
}

std::pair<int, bool> solve(const std::vector<std::pair<int, int>>& opvals) {
	bool visited[opvals.size()] = { false };
	int pc = 0, acc = 0;
	while (pc < opvals.size()) {
		if (visited[pc]) {
			break;
		}
		visited[pc] = true;
		std::pair<int, int> opval = opvals[pc];
		if (opval.first == 0) {
			pc++;
		} else if (opval.first == 1) {
			acc += opval.second;
			pc++;
		} else {
			pc += opval.second;
		}
	}
	return std::make_pair(acc, pc == opvals.size());
}

int main(int, char**) {
	std::vector<std::pair<int, int>> opvals = read_opvals();
	int p2;
	for (int i=0; i<opvals.size(); i++) {
		if (opvals[i].first == 1) continue;
		std::pair<int, int> tmp = opvals[i];
		opvals[i] = std::make_pair(tmp.first == 0 ? 2 : 0, tmp.second);
		std::pair<int, bool> ret = solve(opvals);
		opvals[i] = tmp;
		if (ret.second) {
			p2 = ret.first;
			break;
		}
	}
	std::cout << "Part 1: " << solve(opvals).first << std::endl;
	std::cout << "Part 2: " << p2 << std::endl;
	return 0;
}
