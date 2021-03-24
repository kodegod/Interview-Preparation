//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> v;
        for(auto it:matrix)
            v.push_back(it[0]);
        auto it1=upper_bound(v.begin(),v.end(),target);
        int pos=it1-v.begin()-1;
        if(pos>=r||pos==-1)
            return false;
        cout<<pos;
        auto it2=lower_bound(matrix[pos].begin(),matrix[pos].end(),target);
        int final_pos=it2-matrix[pos].begin();
        if(final_pos>=c)
            return false;
        cout<<final_pos;
        cout<<" "<<final_pos;
        if(matrix[pos][final_pos]==target)
            return true;
        return false;
    }
};
