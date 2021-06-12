//https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,bool> taken;
        for(int i=0; i<s.size(); i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                if(taken[t[i]]==true)
                    return false;
                mp[s[i]]=t[i];
                taken[t[i]]=true;
            }
            else
            {
                if(mp[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};
