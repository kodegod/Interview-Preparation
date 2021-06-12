//https://leetcode.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> mp;
        for(int i=0; i<wall.size(); i++)
        {
            int curr=0,prev=0;
            for(int j=0; j<wall[i].size()-1; j++)
            {
                curr=prev+wall[i][j];
                mp[curr]++;
                prev=curr;
            }
        }
        int ans=0;
        for(auto it:mp)
            ans=max(ans,it.second);
        return wall.size()-ans;
    }
};
