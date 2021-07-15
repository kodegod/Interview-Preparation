//https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/

// ****** FACT ****** Minimum Number of Increasing Subsequences == Longest Decreasing Subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        reverse(nums.begin(),nums.end());   // reverse the array and find LIS == Longest Decreasing Subsequence
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
