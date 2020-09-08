#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	const int MAX_COUNT = pow(2, 31) - 1;

	vector<int> dp;

	int findPS(int n, int cnt) {
		if (n == 0) return cnt;

		if (n < 0) return MAX_COUNT;

		int& ret = dp[n];
		if (ret != -1) {
			return ret;
		}

		cout << n << endl;

		ret = MAX_COUNT;

		int sqrtn = sqrt(n);
		for(int i = sqrtn; i > 0; i--)
		{
			ret = min(ret, findPS(n - i * i, cnt + 1));
		}

		return ret;
	}

	int numSquares(int n) {
		dp.assign(n + 1, -1);

		return findPS(n, 0);
	}
};

int main() {
	cout << Solution().numSquares(1005502);

	return 0;
}