//https://leetcode.com/problems/burst-balloons/

// MCM 

class Solution {
public:
    int dp[502][502];
    int burst(vector<int>&nums,int left,int right)
    {
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        if(left+1==right)
            return 0;
        
        int ans=0;
        for(int i=left+1; i<right; i++)
        {
            int templeft = (dp[left][i]!=-1)?dp[left][i]:burst(nums,left,i);
            int tempright = (dp[i][right]!=-1)?dp[i][right]:burst(nums,i,right);
            int curr_ans = templeft + tempright + nums[left]*nums[i]*nums[right];
            ans=max(ans,curr_ans);
        }
        return dp[left][right] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        memset(dp, -1, sizeof dp);
        return burst(nums,0,nums.size()-1);
    }
};


// Iterative

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n = nums.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for(int gap = 2; gap<n; gap++)
        {
            for(int left=0; left<n-gap; left++)
            {
                int right = left + gap;
                for(int i=left+1; i<right; i++)
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + nums[left]*nums[i]*nums[right]);
            }
        }
        return dp[0][n-1];
    }
};
