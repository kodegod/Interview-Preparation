//https://www.geeksforgeeks.org/shortest-cycle-in-an-undirected-unweighted-graph/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

map<int, vector<int>> g;

int bfs(int src, int n)
{
	vector<int> par(n);
	par[src] = src;
	map<int, bool> visited;
	int ans = INT_MAX;
	vector<int> level(n, INT_MAX);
	visited[src] = true;
	queue<int> q;
	q.push(src);
	level[src] = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (auto it : g[node])
		{
			if (!visited[it])
			{
				par[it] = node;
				visited[it] = true;
				level[it] = level[node] + 1;
				q.push(it);
			}
			else if (it != par[node])
				ans = min(ans, level[it] + level[node] + 1);
		}
	}
	return ans;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
		ans = min(ans, bfs(i, n));
	cout << ans;
	return 0;
}
