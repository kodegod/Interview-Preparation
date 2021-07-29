//https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

int dp[102][102];

int solve(vector<int> &arr, int N,int i,int j)
{
    if(i==j)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int ans = INT_MAX;
    
    for(int right = i; right<j; right++)
    {
        int a = arr[i];
        int b = arr[right+1];
        int c = arr[j+1];
        ans = min(ans, solve(arr,N,i,right) + solve(arr,N,right+1,j) + a*b*c);
    }
    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    memset(dp, -1, sizeof dp);
    return solve(arr,N,0,N-2);
    // Write your code here.
}
