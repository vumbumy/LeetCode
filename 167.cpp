#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int length = numbers.size();

        unordered_set<int> uset;

        for(int i=0;i<length;i++) {
            if(uset.find(numbers[i])!=uset.end()) {
                continue;
            }

            uset.insert(numbers[i]);
            for(int j=i+1;j<length;j++) {
                int sum = numbers[i] + numbers[j];
                if (sum == target) {
                    return vector<int>{i+1, j+1};
                } else if (sum > target) {
                    break;
                }
            }
        }

        return vector<int>();
    }
};

int main() {
    Solution s = Solution();

    int src[] = {2,7,11,15};
    int n = sizeof(src) / sizeof(src[0]);

    vector<int> nums(src, src + n);

    vector<int> ret = s.twoSum(nums, 9);

    for(const int& n: ret) {
        printf("%d ", n);
    }

    return 0;
}
