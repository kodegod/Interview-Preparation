#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

vector<pair<int, pair<int, int>>> edgelist;
vector<int> par;
int get_root(int u)
{
	if (par[u] == u)
		return u;
	return par[u] = get_root(par[u]);
}
void merge(int u, int v)
{
	int a = get_root(u);
	int b = get_root(v);
	if (a == b)
		return;
	if (rand() % 2)
		par[a] = b;
	else
		par[b] = a;
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
		edgelist.push_back({w, {x, y}});
	}
	int mst_cost = 0;
	sort(edgelist.begin(), edgelist.end());
	par.resize(n, 0);
	for (int i = 0; i < n; i++)
		par[i] = i;
	int edges = 0;
	for (auto it : edgelist)
	{
		int a = get_root(it.second.first);
		int b = get_root(it.second.second);
		if (a == b)
			continue;
		else
		{
			mst_cost += it.first;
			merge(it.second.first, it.second.second);
			edges++;
		}
	}
	if (edges == n - 1)
		cout << mst_cost;
	else
		cout << -1;
	return 0;
}
