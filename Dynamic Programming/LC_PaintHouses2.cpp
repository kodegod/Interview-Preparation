//https://leetcode.com/problems/paint-house-ii/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        int dp[n][k];
        for(int i=0; i<k; i++)
            dp[0][i] = costs[0][i];
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                int curr = INT_MAX;
                for(int p=0; p<k; p++)
                {
                    if(p!=j)
                        curr = min(curr,dp[i-1][p]);
                }
                dp[i][j] = curr + costs[i][j];
            }
        }
        int ans = INT_MAX;
        for(int p=0; p<k; p++)
            ans = min(ans,dp[n-1][p]);
        return ans;
    }
};
