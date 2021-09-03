//https://leetcode.com/problems/decode-ways/

class Solution {
public:
    bool isvalid(int n,int k)
    {
        if(k==1)
        {
            if(n>0 && n<10)
                return true;
            return false;
        }
        else
        {
            if(n>9 && n<27)
                return true;
            return false;
        }
    }
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0')
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        dp[1] = 0;
        if(isvalid(s[1]-48,1))
            dp[1]++;
        if(isvalid((s[0]-48)*10 + s[1]-48,2))
            dp[1]++;
        for(int i=2; i<n; i++)
        {
            dp[i] = 0;
            if(isvalid(s[i]-48,1))
                dp[i] += dp[i-1];
            if(isvalid((s[i-1]-48)*10 + s[i]-48,2))
                dp[i] += dp[i-2];
        }
        return dp[n-1];
    }
};
