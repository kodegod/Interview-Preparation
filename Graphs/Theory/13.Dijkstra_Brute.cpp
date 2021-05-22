#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

map<int, vector<pair<int, int>>> g;
map<int, bool> visited;

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
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	vector<int> dist(n, INT_MAX);
	dist[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int k = INT_MAX;
		int node;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && k > dist[j])
			{
				k = dist[j];
				node = j;
			}
		}
		visited[node] = true;
		for (auto child : g[node])
		{
			if (!visited[child.first])
				dist[child.first] = min(dist[child.first], dist[node] + child.second);
		}
	}
	for (int i = 0; i < n; i++)
		cout << dist[i] << " ";
	return 0;
}
