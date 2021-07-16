// https://leetcode.com/problems/best-team-with-no-conflicts/

// LIS

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<int> dp(n,1);
        vector<vector<int>> v;
        for(int i=0; i<n; i++)
            v.push_back({ages[i],scores[i]});
        sort(v.begin(),v.end());
        dp[0]=v[0][1];
        for(int i=1; i<n; i++)
        {
            dp[i]=v[i][1];
            int ans=0;
            for(int j=0; j<i; j++)
            {
                if(v[i][1] >= v[j][1])
                    ans=max(ans,dp[j]);
            }
            dp[i]+=ans;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
