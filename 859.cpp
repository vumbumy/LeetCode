#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.length() != B.length())
			return false;

		map<char, int> charCount;

		bool isNotModeTwo = true;
		for (auto a : A) charCount[a]++;
		for (auto c : charCount) isNotModeTwo &= (c.second < 2);
		for (auto b : B) charCount[b]--;

		for (auto c : charCount) if (c.second != 0) return false;

		charCount.clear();

		int countDiff = 0;
		for (int i = 0; i < A.length(); i++) {
			if (A[i] != B[i])
			{
				charCount[A[i]]++;
				charCount[B[i]]--;

				countDiff++;
			}
		}

		if (countDiff == 2) {
			for (auto c : charCount) if (c.second != 0) return false;
		}
		else if (countDiff == 0) {
			if (isNotModeTwo && A == B) return false;
		}
		else return false;

		return true;
	}
};

int main() {
	printf("%d\n", Solution().buddyStrings("ab", "ab"));
	printf("%d\n", Solution().buddyStrings("ab", "ba"));
	printf("%d\n", Solution().buddyStrings("aab", "baa"));
	printf("%d\n", Solution().buddyStrings("aab", "aab"));
	printf("%d\n", Solution().buddyStrings("aab", "aab"));
	printf("%d\n", Solution().buddyStrings("aabb", "bbaa"));
	printf("%d\n", Solution().buddyStrings("aaaaaaabc", "aaaaaaacb"));
	printf("%d\n", Solution().buddyStrings("", "aa"));
	printf("%d\n", Solution().buddyStrings("aaab", "aaab"));

	return 0;
}