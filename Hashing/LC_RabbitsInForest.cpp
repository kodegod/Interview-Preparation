//https://leetcode.com/problems/rabbits-in-forest/


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(int i=0; i<answers.size(); i++)
            mp[answers[i]]++;
        int ans=0;
        for(auto it:mp)
        {
            while(it.second>0)
            {
                ans+=(it.first+1);
                it.second-=(it.first+1);
            }
        }
        return ans;
    }
};
