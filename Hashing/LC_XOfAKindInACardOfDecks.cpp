//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

// GCD

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mp;
        for(int i=0; i<deck.size(); i++)
            mp[deck[i]]++;
        vector<int> v;
        for(auto it:mp)
            v.push_back(it.second);
        int ans=v[0];
        for(int i=1; i<v.size(); i++)
            ans=__gcd(ans,v[i]);
        return (ans>=2)?true:false;
    }
};
