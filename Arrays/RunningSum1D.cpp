class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v=nums;
        for(int i=1; i<v.size(); i++)
            v[i]+=v[i-1];
        return v;
    }
};
