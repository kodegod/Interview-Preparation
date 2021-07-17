//https://www.geeksforgeeks.org/count-possible-ways-to-construct-buildings/

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
    int dp[n + 1][4];
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1; // no
    dp[1][3] = 1; // both
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][3] = dp[i - 1][2];
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3];
    return 0;
}
