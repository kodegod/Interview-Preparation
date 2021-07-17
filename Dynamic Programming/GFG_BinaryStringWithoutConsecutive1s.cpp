//https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1#

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    int n;
    cin >> n;
    int dp[n][2];
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n - 1][0] + dp[n - 1][1];
    return 0;
}
