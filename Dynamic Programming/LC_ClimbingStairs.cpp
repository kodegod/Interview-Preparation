//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    long long dp[46];
    void init()
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < 46; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    int climbStairs(int n) {
        init();
        return dp[n];
    }
};
