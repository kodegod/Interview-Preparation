//https://www.geeksforgeeks.org/sum-products-possible-subsets/

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
    vector<int> dp(n + 1);
    dp[0] = v[0];
    for (int i = 1; i < n; i++)
        dp[i] = v[i] + v[i] * dp[i - 1] + dp[i - 1];
    cout << dp[n - 1];

    return 0;
}
