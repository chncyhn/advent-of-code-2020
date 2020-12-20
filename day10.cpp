#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

std::vector<int> read_jolts() {
	std::fstream fs("data10.txt", std::ios_base::in);
	std::vector<int> jolts = { 0 };
	int inp;
	while (fs >> inp) {
		jolts.push_back(inp);
	}
	std::sort(jolts.begin(), jolts.end());
	return jolts;
}

int main(int, char**) {
	std::vector<int> jolts = read_jolts();
	int maxJolt = *max_element(std::begin(jolts), std::end(jolts)) + 3;
	jolts.push_back(maxJolt);

	int oneDiff=0, threeDiff=0;
	long dp[maxJolt+1] = {0};
	dp[0] = 1;
	for (int i=1; i<jolts.size(); i++) {
		int diff = jolts[i]-jolts[i-1];
		if (diff == 1) oneDiff++;
		else if (diff == 3) threeDiff++;

		for (int j=0; j<=3 && (jolts[i]-j)>=0; j++) {
			dp[jolts[i]] += dp[jolts[i]-j];
		}
	}
	std::cout << "Part 1: " << oneDiff * threeDiff << std::endl;
	std::cout << "Part 2: " << dp[maxJolt] << std::endl;
	return 0;
}
