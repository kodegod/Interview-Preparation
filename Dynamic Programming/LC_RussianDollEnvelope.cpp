//https://leetcode.com/problems/russian-doll-envelopes/

// O(NLogN)

class Solution {
public:
    static bool compare(vector<int> v1, vector<int> v2)
    {
        if(v1[0] < v2[0])
            return true;
        else if(v1[0] == v2[0])
            return v1[1]>v2[1];
        return false;      
    }
    int lis(vector<int>&v)
    {
        int n=v.size();
        vector<int> dp;
        for(int i=0; i<n; i++)
        {
            if(dp.size()==0 || dp.back() < v[i])
                dp.push_back(v[i]);
            else
            {
                auto it=lower_bound(dp.begin(),dp.end(),v[i]);
                *it = v[i];
            }
        }
        return dp.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> temp;
        for(auto it:envelopes)
            temp.push_back(it[1]);
        return lis(temp);
    }
};
