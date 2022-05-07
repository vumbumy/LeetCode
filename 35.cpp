#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = -1;

        if(target > nums[hi -1]) {
            return hi;
        }

        if(target <= nums[0]) {
            return 0;
        }

        int mid = 0;
        while(true) {
            mid = (hi + lo) / 2;

            if(mid == lo || mid == hi) {
                break;
            }

            if(target > nums[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return mid + 1;
    }
};

int main() {
    Solution s = Solution();

    int src[] = {1,3,5,6};
    int n = sizeof(src) / sizeof(src[0]);

    vector<int> nums(src, src + n);

    printf("%d", s.searchInsert(nums, 4));

    return 0;
}
