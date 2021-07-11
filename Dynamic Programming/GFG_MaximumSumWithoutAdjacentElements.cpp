//https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

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
    vector<int> dp(n + 1);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[0] = v[0];
    dp[1] = v[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], v[i] + dp[i - 2]);
    }
    cout << dp[n - 1];
    return 0;
}
