//https://cses.fi/problemset/task/1132/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 500005
#define ii pair<int,int>

int U[N];
int V[N];
int W[N];
map<int, vector<int>> adj;
vector<int> dp(N, 1);
map<int, bool> vis;

void add_edge(int e, int x, int y, int w)
{
    U[e] = x;
    V[e] = y;
    W[e] = w;
    adj[x].push_back(e);
}

void dfs(int xe)
{
    if (vis[xe] == true)
        return;
    vis[xe] = true;
    for (auto ye : adj[V[xe]])
    {
        if (ye != (xe ^ 1))
        {
            dfs(ye);
            dp[xe] = max(dp[xe], dp[ye] + W[ye]);
        }
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    int n, m;
    cin >> n;
    m = n - 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        int w = 1;
        add_edge(2 * i, x, y, w);
        add_edge(2 * i + 1, y, x, w);
    }
    for (int i = 1; i <= m; i++)
    {
        if (vis[2 * i] == false)
            dfs(2 * i);
        if (vis[2 * i + 1] == false)
            dfs(2 * i + 1);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto ye : adj[i])
            ans[i] = max(ans[i], dp[ye]);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
