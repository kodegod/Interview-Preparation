//https://leetcode.com/problems/longest-happy-prefix/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        int len = 0;
        for(int i=1; i<s.size();)
        {
            if(s[i] == s[len])
            {
                lps[i] = ++len;
                i++;
            }
            else
            {
                if(len > 0)
                    len = lps[len - 1];
                else
                {
                    len = 0;
                    i++;
                }
            }
        }
        string ans;
        int leg = lps[n-1];
        int j = n - leg;
        while(j<n)
            ans.push_back(s[j++]);
        return ans;
    }
};
