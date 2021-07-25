//https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int x = primes.size();
        vector<int> curr(x,0);
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=1; i<n; i++)
        {
            int mini = INT_MAX;
            for(int j=0; j<x; j++)
                mini = min(mini, primes[j] * dp[curr[j]]);
            dp[i] = mini;
            for(int j=0; j<x; j++)
            {
                if(mini == primes[j] * dp[curr[j]])
                    curr[j]++;
            }
        }
        return dp[n-1];
    }
};
