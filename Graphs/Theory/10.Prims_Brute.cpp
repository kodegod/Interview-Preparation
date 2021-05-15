#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005

map<int, vector<pair<int, int>>> graph;
map<int, bool> visited;
vector<int> key;

int prims(int src, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int mini = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if (key[j] < mini && !visited[j])
				mini = j;
		}
		visited[mini] = true;
		for (auto child : graph[mini])
			key[child.first] = min(key[child.first], child.second);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += key[i];
	return sum;
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
		graph[x].push_back({y, w});
		graph[y].push_back({x, w});
	}
	key.resize(n, INT_MAX);
	key[0] = 0;
	cout << prims(0, n);
	return 0;
}
