#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        stringstream ss(s);

        string temp;

        string sss;
 
        while (getline(ss, temp, ' ')) {
            if (sss == "") {
                sss = temp;
            } else {
                sss = temp + ' ' + sss;
            }
        }

        return sss;
    }
};

int main() {
    cout << Solution().reverseWords("God Ding");

	return 0;
}