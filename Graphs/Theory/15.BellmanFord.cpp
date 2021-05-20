#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> edgelist;
	vector<int> ans(n, INT_MAX);
	ans[0] = 0;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edgelist.push_back({{x, y}, w});
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (auto it : edgelist)
		{
			if (ans[it.first.first] == INT_MAX)
				continue;
			if (ans[it.first.second] > ans[it.first.first] + it.second)
				ans[it.first.second] = ans[it.first.first] + it.second;
		}
	}
	for (auto it : ans)
		cout << it << " ";
	return 0;
}
