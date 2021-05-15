#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005

map<int, vector<int>> graph;
map<int, bool> visited;

void dfs(int src)
{
	cout << src << " ";
	visited[src] = true;
	for (auto child : graph[src])
	{
		if (!visited[child])
			dfs(child);
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
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
	return 0;
}
