#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

map<int, vector<pair<int, int>>> g;
map<int, bool> vis;
vector<int> dist;

void dijkstra(int src)
{
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, src});
	while (!pq.empty())
	{
		ii node = pq.top();
		pq.pop();
		if (vis[node.second] == true)
			continue;
		else
			vis[node.second] = true;
		for (auto child : g[node.second])
		{
			int nbr = child.first;
			int wt = child.second;
			if (dist[nbr] > dist[node.second] + wt)
			{
				dist[nbr] = dist[node.second] + wt;
				pq.push({dist[nbr], nbr});
			}
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
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	dist.resize(n, INT_MAX);
	dist[0] = 0;
	dijkstra(0);
	for (int i = 0; i < n; i++)
		cout << dist[i] << " ";
	return 0;
}
