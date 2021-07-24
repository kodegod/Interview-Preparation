//https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int dp[1002][1002];
    int solve(string&s,int i,int j)
    {
        if(i==j)
            return 1;
        else if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j] = 2 + solve(s,i+1,j-1);
        else
            return dp[i][j] = max(solve(s,i+1,j),solve(s,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof dp);
        return solve(s,0,s.size()-1);
    }
};
