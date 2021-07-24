//https://www.codingninjas.com/codestudio/problems/lcs-of-3-strings_842499?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int dp[102][102][102];
int solve(string&A, string&B, string&C, int i, int j, int k)
{
    if(i==-1 || j==-1 || k==-1)
        return 0;
    
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    
    if(A[i] == B[j] && A[i] == C[k])
        return dp[i][j][k] = 1 + solve(A,B,C,i-1,j-1,k-1);
    else
    {
        int op1 = solve(A,B,C,i-1,j,k);
        int op2 = solve(A,B,C,i,j-1,k);
        int op3 = solve(A,B,C,i,j,k-1);
        return dp[i][j][k] = max(op1,max(op2,op3));
    }
}
int LCS(string A, string B, string C, int n, int m, int k)
{
	// Write your code here.
    memset(dp, -1, sizeof dp);
    return solve(A,B,C,n-1,m-1,k-1);
}
