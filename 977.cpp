#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int& n : nums) {
            n = n*n;
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};

int main() {
    Solution s = Solution();

    int src[] = {-7,-3,2,3,11};
    int n = sizeof(src) / sizeof(src[0]);

    vector<int> nums(src, src + n);

    s.sortedSquares(nums);

    for(const int& n : nums) {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}
