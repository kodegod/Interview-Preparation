//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    map<int,int> mp;
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> psum(n);
        psum[0]=nums[0];
        for(int i=1; i<n; i++)
            psum[i]=nums[i]+psum[i-1];
        mp[0]=1;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            cnt+=mp[psum[i]-k];
            mp[psum[i]]++;
        }
        return cnt;
    }
};
