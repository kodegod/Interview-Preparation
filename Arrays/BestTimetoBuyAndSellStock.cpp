class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        if(n<=1)
            return 0;
        vector<int> sm(n);
        sm[n-1]=prices[n-1];
        for(int i=n-2; i>=0; i--)
            sm[i]=max(sm[i+1],prices[i]);
        for(int i=0; i<n-1; i++)
        {
            int profit=sm[i+1]-prices[i];
            ans=max(ans,profit);
        }
        return ans;
    }
};
