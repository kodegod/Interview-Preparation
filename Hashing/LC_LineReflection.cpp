//https://leetcode.com/problems/line-reflection/

// Good Q

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int mini=INT_MAX;
        int maxy=INT_MIN;
        for(auto v:points)
        {
            mini=min(mini,v[0]);
            maxy=max(maxy,v[0]);
        }
        int mirror=maxy+mini;        // 2*mirror
        map<pair<int,int>,bool> mp;
        for(auto v:points)
            mp[{v[0],v[1]}]=true;
        for(auto v:points)
        {
            if(v[0]!=mirror)
                if(mp[{mirror-v[0],v[1]}]==false).  // 2*mirror
                    return false;
        }
        return true;
    }
};
