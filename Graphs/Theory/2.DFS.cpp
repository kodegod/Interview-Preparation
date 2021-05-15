#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005

map<int, vector<int>> graph;
map<int, bool> visited;

void bfs(int src)
{
	queue<int> q;
	visited[src] = true;
	q.push(src);
	while (!q.empty())
	{
		int node = q.front();
		cout << node << " ";
		q.pop();
		for (auto child : graph[node])
		{
			if (!visited[child])
			{
				q.push(child);
				visited[child] = true;
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
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(0);
	return 0;
}
