//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int dp[5005][2];
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1; i<n; i++)
        {
            dp[i][0]=max(dp[i-1][0], dp[i-1][1] + prices[i]);
            if(i==1)
                dp[i][1]=max(dp[i-1][1], dp[i-1][0] - prices[i]);
            else
                dp[i][1]=max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};
