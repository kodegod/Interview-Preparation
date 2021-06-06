//https://codeforces.com/contest/1520/problem/D

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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 0; i < n; i++)
		{
			v[i] -= i;
			mp[v[i]]++;
		}
		int ans = 0;
		for (auto it : mp)
			ans += (it.second * (it.second - 1)) / 2;
		cout << ans << endl;
	}

	return 0;
}
