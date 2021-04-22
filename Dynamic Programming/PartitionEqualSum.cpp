//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum%2==1)
            return false;
        sum/=2;
        int dp[n+1][sum+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
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
                    if(nums[i-1]<=j)
                        dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};
