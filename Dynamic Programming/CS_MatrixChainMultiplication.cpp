//https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?leftPanelTab=1

// MCM

//Recursive
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

// Iterative

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    int M = N-1; // Number of matrices
    int dp[N-1][N-1];
    for(int i=0; i<N-1; i++)
        dp[i][i] = 0;
    for(int d=1; d<N-1; d++)
    {
        int i = 0, j = d;
        while(i<N-1 && j<N-1)
        {
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i]*arr[k+1]*arr[j+1]);
            i++;
            j++;
        }
    }
    return dp[0][N-2];
}
