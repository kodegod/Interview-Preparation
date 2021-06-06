//https://leetcode.com/problems/subarray-sum-equals-k/


// O(2N) (Two passes)
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


// O(N) (One pass)

class Solution {
public:
    map<int,int> mp;
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int curr=0;
        int prev=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0; i<n; i++)
        {
            curr=prev+nums[i];
            cnt+=mp[curr-k];
            mp[curr]++;
            prev=curr;
        }
        return cnt;
    }
};
