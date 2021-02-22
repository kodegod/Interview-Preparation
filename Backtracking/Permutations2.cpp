class Solution {
public:
    void solve(vector<int> num,int i,vector<vector<int>>&v)
    {
        if(i==num.size())
        {
            v.push_back(num);
            return;
        }
        set<int> s;
        for(int j=i; j<num.size(); j++)
        {
            if(s.find(num[j])==s.end())
            {
                s.insert(num[j]);
                swap(num[i],num[j]);
                solve(num,i+1,v);
                swap(num[i],num[j]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        solve(nums,0,v);
        return v;
    }
};
