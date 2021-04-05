//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284
int cutRod(vector<int> &price, int n) {
    // Write your code here
    vector<int> dp(n+1,0);
    for(int i=1; i<=n; i++)
    {
        for(int k=1; k<=i; k++)
            dp[i]=max(dp[i],price[k-1]+dp[i-k]);
    }
    return dp[n];
}
