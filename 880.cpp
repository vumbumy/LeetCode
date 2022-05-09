#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    int count = 0;
    vector<int> indexes;
    vector<int> lengths;
    vector<int> decodeds;
public:
    int getMaxLength() {
        int length = 0;

        for(int i=0;i<count;i++) {
            length += lengths[i];
            length *= decodeds[i];
        }

        return length;
    }
    int getIndex(int K) {

    }
	string decodeAtIndex(string S, int K) {
	    int index = 0;
	    int length = 0;
	    int decoded = 1;

	    int kk = K;

	    bool need_init = false;
		for (int i = 0; i < S.length();i++) {
            bool locked = false;
		    if('0' <= S[i] && S[i] <='9') {
		        decoded *= S[i] - '0';

		        need_init = true;
		    } else {
		        if(need_init) {
		            count++;

                    indexes.push_back(i);
		            lengths.push_back(length);
		            decodeds.push_back(decoded);

		            length = 0;
		            decoded = 1;

		            need_init = false;
		        }
		        length++;
		    }

		    if(K <= getMaxLength()) {
		        return string(1, S[getIndex(K)]);
		    }
		}

		return "";
	}
};

int main() {
	cout << Solution().decodeAtIndex("a2b3c4d5e6f7g8h9", 10) << endl;
//	cout << Solution().decodeAtIndex("leet2code3", 10) << endl;
//	cout << Solution().decodeAtIndex("ha22", 5) << endl;
//	cout << Solution().decodeAtIndex("a2345678999999999999999", 1) << endl;
//	cout << Solution().decodeAtIndex("y959q969u3hb22odq595", 222280369) << endl;
//	cout << Solution().decodeAtIndex("a2b3c4d5e6f7g8h9", 9) << endl;

	return 0;
}