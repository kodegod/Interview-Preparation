#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005

int b = 0;
vector<int> block, arr, lazy;

int query(int l, int r)
{
	int sum = 0;
	while (l % b != 0 && l <= r)
	{
		sum += arr[l] + lazy[l / b];
		l++;
	}
	while (l + b <= r)
	{
		sum += block[l / b] + b * lazy[l / b];
		l += b;
	}
	while (l <= r)
	{
		sum += arr[l] + lazy[l / b];
		l++;
	}
	return sum;
}

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
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(l, r) << endl;
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
