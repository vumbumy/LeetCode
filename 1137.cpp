#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> dp;

	int func(int n){
		int& ret = dp[n];
		if(ret != -1){
			return ret;
		}

		return ret = func(n - 1) + func(n - 2) + func(n - 3);
	}

    int tribonacci(int n) {
		dp.assign(38, -1);

		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;

		return func(n);
    }
};

int main() {
	// int n; cin >> n;

	printf("%d\n", Solution().tribonacci(0));

	return 0;
}