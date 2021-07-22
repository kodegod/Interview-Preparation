//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0 || k==0)
            return 0;
        int hasStock[k][n];
        int noStock[k][n];
        for(int i=0; i<k; i++)
        {
            hasStock[i][0] = -prices[0];
            noStock[i][0] = 0;
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(j==0)
                    hasStock[j][i] = max(hasStock[j][i-1], -prices[i]);
                else
                    hasStock[j][i] = max(hasStock[j][i-1], noStock[j-1][i-1] - prices[i]);
                noStock[j][i] = max (noStock[j][i-1], hasStock[j][i-1] + prices[i]);
            }
        }
        return noStock[k-1][n-1];
    }
};
