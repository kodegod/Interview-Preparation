//https://leetcode.com/problems/range-addition/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> v(length,0);
        for(auto it: updates)
        {
            v[it[0]]+=it[2];
            if(it[1]<length-1)
                v[it[1]+1]-=it[2];
        }
        int sum = 0;
        for(int i=0; i<length; i++)
        {
            sum+= v[i];
            v[i] = sum;
        }
        return v;
    }
};
