//https://www.codechef.com/ZCOPRAC/problems/ZCO14004

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
    dp[0][0] = v[0];
    dp[0][1] = v[0];
    dp[1][0] = v[1];
    dp[1][1] = v[0] + v[1];
    int ans = INT_MIN;
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = v[i] + max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][1] = v[i] + dp[i - 1][0];
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}
