#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string decodeAtIndex(string S, int K) {
		for (int i = 0; i < S.length();i++) {
			int strLength = -1;

			//printf("char: %c\n", S[i]);
			if ('0' <= S[i] && '9' >= S[i]) {
				strLength = i;
			}

			if (strLength == -1)
				continue;

			/*printf("strLength: %d\n", strLength);*/

			int repeat = S[i] - '0';
			string repeatedStr = "";
			for (int j = 0; j < repeat; j++) {
				//cout << S.substr(0, strLength) << endl;
				repeatedStr += S.substr(0, strLength);

				if (K - 1 < repeatedStr.length()) {
					//cout << S << " / " << K << endl;
					return string(1, repeatedStr[K - 1]);
				}
			}

			i = repeat * strLength - 1 ;

			S.replace(0, strLength + 1, repeatedStr);
		}

		if (K - 1 < S.length()) {
			//cout << S << " / " << K - 1 << endl;
			return string(1, S[K - 1]);
		}

		return "";
	}
};

int main() {
	cout << Solution().decodeAtIndex("leet2code3", 10) << endl;
	cout << Solution().decodeAtIndex("ha22", 5) << endl;
	cout << Solution().decodeAtIndex("a2345678999999999999999", 1) << endl;
	cout << Solution().decodeAtIndex("y959q969u3hb22odq595", 222280369) << endl;

	return 0;
}