//https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<amount+1; j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0)
                        dp[i][j]=false;
                    if(j==0)
                        dp[i][j]=true;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    if(j>=coins[i-1])
                        dp[i][j]=dp[i][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};
