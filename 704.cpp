#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = -1;

        int mid = -1;
        while(true) {
            mid = (hi + lo) / 2;

            if(mid == lo || mid == hi) {
                break;
            }

            printf("%d %d\n", mid, nums[mid]);

            if(target == nums[mid]) {
                return mid;
            }

            if(target > nums[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return -1;
    }
};

int main() {
    Solution s = Solution();

    int src[] = {-1,0,3,5,9,12};
    int n = sizeof(src) / sizeof(src[0]);

    vector<int> nums(src, src + n);

    printf("%d", s.search(nums, -1));

    return 0;
}
