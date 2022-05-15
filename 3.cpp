#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c_set;

        queue<char> c_q;

        int longest = 0;
        for (char c : s) {
            if (c_set.find(c) != c_set.end()) {
                while (true) {
                    char f = c_q.front();

                    c_q.pop();
                    c_set.erase(f);

                    if (f == c) {
                        break;
                    }
                }
            }

            c_q.push(c);
            c_set.insert(c);

            int len = static_cast<int>(c_q.size());

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
    printf("%d\n", s.lengthOfLongestSubstring("aaaa"));
    printf("%d\n", s.lengthOfLongestSubstring("zzzz"));

    return 0;
}
