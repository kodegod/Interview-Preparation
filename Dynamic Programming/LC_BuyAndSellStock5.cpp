//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int hasStock[2][n];
        int noStock[2][n];
        hasStock[0][0] = -prices[0];
        hasStock[1][0] = -prices[0];
        noStock[0][0] = 0;
        noStock[1][0] = 0;
        for(int i=1; i<n; i++)
        {
            hasStock[0][i] = max(hasStock[0][i-1], -prices[i]);
            noStock[0][i] = max(noStock[0][i-1], hasStock[0][i-1] + prices[i]);
            hasStock[1][i] = max(hasStock[1][i-1], noStock[0][i-1] - prices[i]);
            noStock[1][i] = max(noStock[1][i-1], hasStock[1][i-1] + prices[i]);
        }
        return noStock[1][n-1];
    }
};
