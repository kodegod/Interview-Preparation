class Solution {
public:
    void solve(vector<int> ip,vector<int>op,vector<vector<int>>&v,map<int,int>&freq)
    {
        if(op.size()==0)
        {
            sort(ip.begin(),ip.end());
            v.push_back(ip);
            return;
        }
        vector<int> temp=ip;
        int k=op[0];
        op.erase(op.begin());
        solve(ip,op,v,freq);
        int xp=freq[k];
        while(xp>0)
        {
            temp.push_back(k);
            solve(temp,op,v,freq); 
            xp--;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> freq;
        vector<vector<int>> v;
        if(nums.size()==0)
            return v;
        for(auto it:nums)
            freq[it]++;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        vector<int> ip;
        vector<int> op=nums;
        solve(ip,op,v,freq);
        return v;
    }
};
