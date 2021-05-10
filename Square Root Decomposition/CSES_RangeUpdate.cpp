//https://cses.fi/problemset/task/1651
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
 
int b = 0;
vector<int> block, arr, lazy;
 
void update(int l, int r, int u)
{
	while (l % b != 0 && l <= r)
		arr[l++] += u;
	while (l + b <= r)
	{
		lazy[l / b] += u;
		l += b;
	}
	while (l <= r)
		arr[l++] += u;
}
 
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n, q;
	cin >> n >> q;
	b = sqrt(n);
	int sz = (n + b + 1) / b;
	block.resize(sz, 0);
	arr.resize(n, 0);
	lazy.resize(sz, 0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
		block[i / b] += a;
	}
	while (q--)
	{
		int temp;
		cin >> temp;
		if (temp == 2)
		{
			int k;
			cin >> k;
			k--;
			cout << arr[k] + lazy[k / b] << endl;
		}
		else
		{
			int l, r, u;
			cin >> l >> r >> u;
			l--;
			r--;
			update(l, r, u);
		}
	}
}
