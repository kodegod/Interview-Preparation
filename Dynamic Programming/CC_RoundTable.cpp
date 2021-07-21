//https://www.codechef.com/ZCOPRAC/problems/ZCO12004

// Very Good Q

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
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = INT_MAX;
    dp[1][0] = INT_MAX;
    dp[1][1] = v[1];
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = v[i] + min(dp[i - 1][1], dp[i - 1][0]);
    }
    int ans1 = dp[n - 1][1];
    dp[0][0] = INT_MAX;
    dp[0][1] = v[0];
    dp[1][0] = v[0];
    dp[1][1] = v[1] + v[0];
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = v[i] + min(dp[i - 1][1], dp[i - 1][0]);
    }
    int ans2 = min(dp[n - 1][0], dp[n - 1][1]);
    cout << min(ans1, ans2);
    return 0;
}
