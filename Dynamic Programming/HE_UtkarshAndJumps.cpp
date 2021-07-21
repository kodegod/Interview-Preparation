//https://www.hackerearth.com/problem/algorithm/utkarsh-and-jumps/

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
    double p;
    cin >> p;
    double dp[n + 1];
    dp[1] = (double) 0;
    dp[2] = (double) (p / 100);
    dp[3] = (double) 1 - dp[2];
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (double) dp[2] * dp[i - 2] + dp[3] * dp[i - 3];
    }
    cout << fixed << setprecision(6) << dp[n];
    return 0;
}
