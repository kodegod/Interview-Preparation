//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> s;
        s.push(0);
        for(int i=1; i<n; i++)
        {
            while(prices[i] <= prices[s.top()])
            {
                prices[s.top()] -= prices[i];
                s.pop();
                if(s.empty())
                    break;
            }
            s.push(i);
        }
        return prices;
    }
};
