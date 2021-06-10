//https://codeforces.com/contest/1526/problem/C2

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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	int curr_health = 0;
	int ans = 0;
	bool bar = true;
	for (int i = 0; i < n; i++)
	{
		ans++;
		curr_health += v[i];
		pq.push(v[i]);
		if (curr_health < 0)
		{
			if (pq.empty())
			{
				bar = false;
				break;
			}
			curr_health -= pq.top();
			pq.pop();
			ans--;
		}
	}
	if (bar == false)
		cout << -1;
	else
		cout << ans;
	return 0;
}
