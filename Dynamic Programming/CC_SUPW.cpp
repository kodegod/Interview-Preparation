//https://www.codechef.com/ZCOPRAC/problems/ZCO14002

// Very good Problem


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
    vector<int> dp(n, 0);
    dp[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        if (i < 3)
            dp[i] = min(v[i], dp[i - 1]);
        else
            dp[i] = v[i] + min(dp[i - 1], min(dp[i - 2], dp[i - 3]));
    }
    if (n < 3)
        cout << *min_element(v.begin(), v.end());
    else
        cout << min(dp[n - 1], min(dp[n - 2], dp[n - 3]));
    return 0;
}
