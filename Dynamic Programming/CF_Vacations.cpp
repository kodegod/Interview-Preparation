// https://codeforces.com/contest/698/problem/A

// Very good Q

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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int dp[n][3];
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        dp[i][2] = INT_MAX;
    }
    dp[0][0] = 1;
    if (v[0] == 1 || v[0] == 3)
        dp[0][1] = 0;
    if (v[0] == 2 || v[0] == 3)
        dp[0][2] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
        if (v[i] == 1 || v[i] == 3)
            dp[i][1] = min(dp[i - 1][0],  dp[i - 1][2]);
        if (v[i] == 2 || v[i] == 3)
            dp[i][2] = min(dp[i - 1][0],  dp[i - 1][1]);
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

    return 0;
}
