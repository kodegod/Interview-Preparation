//https://leetcode.com/problems/longest-increasing-subsequence/

// O(N2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
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

// Improved LIS - O(NLogN)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        for(int i=0; i<n; i++)
        {
            if(curr.size()==0 || nums[i]>curr.back())
                curr.push_back(nums[i]);
            else
            {
                auto it = lower_bound(curr.begin(),curr.end(),nums[i]);
                *it = nums[i];
            }
        }
        return curr.size();
    }
};



// Not using inbuilt binary search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> curr;
        for(int k=0; k<n; k++)
        {
            int i=0,j=curr.size();
            while(i<j)
            {
                int mid=i+(j-i)/2;
                if(curr[mid]<nums[k])
                    i=mid+1;
                else 
                    j=mid;
            }
            if(i==curr.size())
                curr.push_back(nums[k]);
            else
                curr[i]=nums[k];
        }
        return curr.size();
    }
};
