#include<bits/stdc++.h>
using namespace std;

#define int long

int  bs = 0;
vector<int> blocks, arr;

int query(int l, int r)
{
	int sum = 0;
	while (l % bs != 0 && l <= r)
		sum += arr[l++];
	while (l + bs <= r)
	{
		sum += blocks[l / bs];
		l += bs;
	}
	while (l <= r)
		sum += arr[l++];
	return sum;
}

void update(int idx, int val)
{
	blocks[idx / bs] = blocks[idx / bs] - arr[idx] + val;
	arr[idx] = val;
}

void solve()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	bs = (int)sqrt(n) + 1;
	blocks.resize(bs + 1, 0);
	arr.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
		blocks[i / bs] += a;
	}
	while (q--)
	{
		int c;
		cin >> c;
		if (c == 2) //query
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(l, r) << endl;
		}
		else	 //update
		{
			int idx, val;
			cin >> idx >> val;
			idx--;
			update(idx, val);
		}
	}
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
