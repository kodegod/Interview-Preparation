//https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int,set<int>> dp;
        dp[stones[0]].insert(1);
        for(int i=0; i<n; i++)
        {
            set<int> s = dp[stones[i]];
            for(int j=0; j<s.size(); j++)
            {
                auto it = s.begin();
                int k = j;
                while(k--)
                    it++;
                int x = *it;
                k = x;
                x += stones[i];
                dp[x].insert(k-1);
                dp[x].insert(k);
                dp[x].insert(k+1);
            }
        }
        return (dp[stones[n-1]].size()>0)?true:false;
    }
};
