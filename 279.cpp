#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int MAX_COUNT;

    vector<int> dp;

    int findPS(int n) {
        int& ret = dp[n];
        if (ret != -1) {
            return ret;
        }

        ret = MAX_COUNT;

        int sqrtn = sqrt(n);
        for(int i = sqrtn; i > 0; i--)
        {
            int next = n - i * i;
            
            if(next >= 0)
                ret = min(ret, findPS(next) + 1);
        }

        return ret;
    }

    int numSquares(int n) {
        MAX_COUNT = n;
        
        dp.assign(n + 1, -1);
        dp[0] = 0;

        return findPS(n);
    }
};

int main(){
    cout << Solution().numSquares(48) << endl;
    
    return 0;
}
