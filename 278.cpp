#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int bad;
public:
    Solution() {
        this->bad = 1;
    }

    bool isBadVersion(int version) {
        return version >= bad;
    }

    int firstBadVersion(int n) {
        unsigned int hi = n + 1;
        int lo = -1;

        unsigned int mid = 0;

        int isFound = -1;
        while(true) {
            mid = (hi + lo) / 2;
//            printf("%d\n", mid);

            if(mid == lo || mid == hi) {
                break;
            }

            if(isBadVersion(mid)) {
                hi = mid;

                isFound = mid;
            } else {
                lo = mid;
            }
        }

        return isFound;
    }
};

int main() {
    Solution s = Solution();

    printf("%d\n", s.firstBadVersion(2147483647));
    printf("%d\n", s.firstBadVersion(2147483647));

    return 0;
}