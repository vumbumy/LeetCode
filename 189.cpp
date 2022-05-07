#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();

        k = k % length;

        vector<int> copied = {nums.begin(), nums.end()};

        for(int i=0; i<length; i++) {
            nums[(i + k) % length] = copied[i];
        }
    }
};

int main() {
    Solution s = Solution();

    int src[] = {1,2,3,4,5,6,7};
    int n = sizeof(src) / sizeof(src[0]);

    vector<int> nums(src, src + n);

    s.rotate(nums, 3);

    for(const int& n : nums) {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}
