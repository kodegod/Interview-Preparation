//https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

// Very good Q

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int,int> mp;
        int prev=0;
        int curr=0;
        mp[0]=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            curr=prev+nums[i];
            if(mp.find(curr-k)!=mp.end())
                ans=max(ans,i+1-mp[curr-k]);
            if(mp.find(curr)==mp.end())
                mp[curr]=i+1;
            prev=curr;
        }
        return ans;
    }
};
