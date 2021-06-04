//https://leetcode.com/problems/longest-consecutive-sequence/

// DSU

class Solution {
public:
    map<int,int> par;
    map<int,int> sz;
    int get_root(int u)
    {
        if(par[u]==u)
            return u;
        return par[u]=get_root(par[u]);
    }
    void merge(int u,int v)
    {
        int a=get_root(u);
        int b=get_root(v);
        if(a==b)
            return;
        if(sz[b]>sz[a])
        {
            par[a]=b;
            sz[b]+=sz[a];
        }
        else
        {
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int k=*min_element(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            nums[i]-=k;
            sz[nums[i]]=1;
            par[nums[i]]=nums[i];
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=0 && par.find(nums[i]-1)!=par.end())
                merge(nums[i]-1,nums[i]);
            if(par.find(nums[i]+1)!=par.end())
                merge(nums[i]+1,nums[i]);
        }
        int ans=INT_MIN;
        for(auto it:sz)
            ans=max(ans,it.second);
        return ans;
    }
};
