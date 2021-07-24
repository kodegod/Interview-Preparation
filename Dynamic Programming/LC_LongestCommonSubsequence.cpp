//https://leetcode.com/problems/longest-common-subsequence/


// Recursive 

class Solution {
public:
    int dp[1002][1002];
    int solve(string&text1, string&text2,int i,int j)
    {
        if(i==-1 || j==-1)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        if(text1[i] == text2[j])
            ans = 1 + solve(text1,text2,i-1,j-1);
        else 
        {
            int op1 = solve(text1,text2,i-1,j);
            int op2 = solve(text1,text2,i,j-1);
            ans = max(op1,op2);
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return solve(text1,text2,text1.size()-1,text2.size()-1);
    }
};



// Iterative


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        memset(dp, 0 ,sizeof dp);
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else
                {
                    if(text1[i-1] == text2[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
