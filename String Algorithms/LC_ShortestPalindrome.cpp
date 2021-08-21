//https://leetcode.com/problems/shortest-palindrome/

class Solution {
public:
    vector<int> lps;
    void calcLPS(string &s,int n)
    {
        lps.resize(n,0);
        int i = 1;
        int len = 0;
        while(i<n)
        {
            if(s[i] == s[len])
            {
                lps[i] = ++len;
                i++;
            }
            else
            {
                if(len>0)
                    len = lps[len-1];
                else
                {
                    len = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string temp = s;
        string t = s;
        reverse(t.begin(),t.end());
        s += "#";
        s += t;
        int n = s.size();
        calcLPS(s,n);
        return t.substr(0, t.size() - lps[n-1]) + temp;
    }
};
