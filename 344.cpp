#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

int main() {
    char src[] = {'h','e','l','l','o'};
    int n = sizeof(src) / sizeof(src[0]);

    vector<char> vec(src, src + n);

	Solution().reverseString(vec);

	for(const char& c : vec) {
		printf("%c\n", c);	
	}

	return 0;
}