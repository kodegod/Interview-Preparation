//https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1#


class Solution {
  public:
    long long numberOfWays(long long N) {
        //code here
        if(N<3)
            return N;
        vector<int> dp(N+1);
        dp[1] = 1;
        dp[2] = 2; 
        for(int i=3; i<=N; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }
        return dp[N];
    }
};
