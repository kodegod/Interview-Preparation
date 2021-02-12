class Solution {
public:
    void helper(vector<int>&nums,int i,vector<vector<int>>&v,vector<int> temp,int size)
    {
        if(nums.size()==i)
        {
            vector<int> p(temp.begin(),temp.begin()+size);
            v.push_back(p);
            return;
        }
        temp[size]=nums[i];
        helper(nums,i+1,v,temp,size+1);
        helper(nums,i+1,v,temp,size);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp(nums.size());
        helper(nums,0,v,temp,0);
        return v;
    }
};
