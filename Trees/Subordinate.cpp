#include<bits/stdc++.h>
using namespace std;

#define int long long

#define N (int)2e5 + 10

vector<pair<int, int>> g[N];

//Properties to calculate
int level[N], par[N], sz[N];
int dist[N], sum[N];

void dfs(int x, int p)
{
	par[x] = p;
	sz[x] = 1;
	for (auto [y, w] : g[x])
	{
		if (y == p)
			continue;
		level[y] = level[x] + 1;
		dist[y] = dist[x] + w;
		dfs(y, x);
		sz[x] += sz[y];
		sum[x] += sum[y] + w;
	}
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x = i;
		int y, w = 1;
		cin >> y;
		g[x].emplace_back(y, w);
		g[y].emplace_back(x, w);
	}
	g[1].emplace_back(1, 1);
	int root = 1;
	dfs(root, root);
	for (int i = 1; i <= n; i++)
		cout << --sz[i] << " ";
}
