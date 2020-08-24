#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());

		int num = -987654321;
		int count = 0;

		for (auto n : nums) {
			if (num != n) {
				num = n;

				count++;
			}

			if (count >= 3) {
				return num;
			}
		}

		return nums[0];
	}
};

int main() {
	vector<int> v{ 3, 2, 2, 3, 1 };

	printf("%d\n", Solution().thirdMax(v));

	return 0;
}