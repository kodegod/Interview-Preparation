//https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[i][j]=grid[i][j];
                int temp=INT_MAX;
                if(i-1>=0)
                    temp=min(temp,dp[i-1][j]);
                if(j-1>=0)
                    temp=min(temp,dp[i][j-1]);
                if(i==0&&j==0)
                    continue;
                dp[i][j]+=temp;
            }
        }
        return dp[m-1][n-1];
    }
};
