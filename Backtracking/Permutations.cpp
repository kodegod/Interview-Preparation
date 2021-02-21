class Solution {
public:
    void permute(vector<int>&ip,int i,vector<vector<int>>&v)
    {
        if(i==ip.size()-1)
        {
            v.push_back(ip);
            return;
        }
        for(int j=i; j<ip.size(); j++)
        {
            swap(ip[i],ip[j]);
            permute(ip,i+1,v);
            swap(ip[i],ip[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permute(nums,0,v);
        return v;
    }
};
