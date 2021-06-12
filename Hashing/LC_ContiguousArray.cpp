//https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int nz=0,no=0,ans=0;
        map<int,int> mp;
        mp[0]=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
                nz++;
            else
                no++;
            if(mp.find(nz-no)==mp.end())
                mp[nz-no]=i+1;
            else
                ans=max(ans,i+1-mp[nz-no]);
        }
        return ans;
    }
};
