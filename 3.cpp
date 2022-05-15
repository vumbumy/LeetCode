#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c_set;

        int longest = 0;
        for (char c : s) {
            if (c_set.find(c) != c_set.end()) {
                c_set.clear();
            }

            c_set.insert(c);

            int len = static_cast<int>(c_set.size());

            longest = max(longest, len);
        }

        return longest;
    }
};

int main() {
    Solution s = Solution();

    printf("%d\n", s.lengthOfLongestSubstring("pwwekew"));
    printf("%d\n", s.lengthOfLongestSubstring(""));
    printf("%d\n", s.lengthOfLongestSubstring("dvdf"));

    return 0;
}
