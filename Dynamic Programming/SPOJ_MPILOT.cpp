//https://www.spoj.com/problems/MPILOT/

// Very good Q

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int n;
vector<pair<int, int>> v;

int dp[10001][5001];


int f(int i, int c, int a)
{
    if (i == n)
        return 0;

    if (dp[i][a] != -1)
        return dp[i][a];

    if (a == n / 2)
        return dp[i][a] = v[i].first + f(i + 1, c + 1, a);
    else if (a == c)
        return dp[i][a] = v[i].second + f(i + 1, c, a + 1);
    else
        return dp[i][a] = min(v[i].first + f(i + 1, c + 1, a) , v[i].second + f(i + 1, c, a + 1));
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, 0);
    return 0;
}

