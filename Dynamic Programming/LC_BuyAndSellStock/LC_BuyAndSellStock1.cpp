//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int max_profit=0;
        for(int i=1; i<n; i++)
        {
            if(prices[i]<mini)
                mini=prices[i];
            max_profit=max(max_profit,prices[i]-mini);
        }
        return max_profit;
    }
};
