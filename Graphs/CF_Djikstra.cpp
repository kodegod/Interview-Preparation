//https://codeforces.com/problemset/problem/20/C
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
vector<int> par;


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
				par[nbr] = node.second;
				if (!vis[nbr])
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
		x--;
		y--;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	dist.resize(n, INT_MAX);
	dist[0] = 0;
	par.resize(n, -1);
	par[0] = 0;
	dijkstra(0);
	if (par[n - 1] == -1)
		cout << -1;
	else
	{
		vector<int> ans;
		int target = n - 1;
		while (target != 0)
		{
			ans.push_back(target);
			target = par[target];
		}
		ans.push_back(target);
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] + 1 << " ";
	}
	return 0;
}
