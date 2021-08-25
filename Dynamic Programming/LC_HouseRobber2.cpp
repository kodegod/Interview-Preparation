//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int dp[n];
        // case 1
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans1 = dp[n-1];
        // case 2
        dp[0] = nums[0];
        dp[1] = nums[0];
        for(int i=2; i<n-1; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans2 = dp[n-2];
        return max(ans1,ans2);
    }
};
