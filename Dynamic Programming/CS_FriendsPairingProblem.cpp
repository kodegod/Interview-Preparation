//https://www.codingninjas.com/codestudio/problems/friends-pairing-problem_1214625?leftPanelTab=1

#define mod 1000000007
int numberOfWays(int n)
{
    // Write your code here.
    if(n<2)
        return n;
    vector<long long> dp(n,0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2; i<n; i++)
    {
        dp[i] = (dp[i-1] + i*dp[i-2])%mod;
    }
    return dp[n-1];
}
