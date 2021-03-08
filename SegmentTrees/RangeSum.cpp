#include<bits/stdc++.h>
using namespace std;

#define int long long

#define lc 2*v
#define rc 2*v+1

const int N = 200005;
int t[4 * N];

void update(int v, int tl, int tr, int pos, int val)
{
	if (tl == tr && tl == pos)
	{
		t[v] = val;
		return;
	}
	if (tl > pos || tr < pos )
		return;
	int tm = (tl + tr) / 2;
	update(lc, tl, tm, pos, val);
	update(rc, tm + 1, tr, pos, val);
	t[v] = t[lc] + t[rc];
}
int query(int v, int tl, int tr, int L, int R)
{
	if (tl > R || tr < L)
		return 0;
	if ( tl >= L && tr <= R)
		return t[v];
	int tm = (tl + tr) / 2;
	int ans = 0;
	ans += query(lc, tl, tm, L, R);
	ans += query(rc, tm + 1, tr, L, R);
	return ans;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		update(1, 0, n - 1, i, v[i]);
	}
	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int k, u;
			cin >> k >> u;
			k--;
			update(1, 0, n - 1, k, u);
		}
		else if (a == 2)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << query(1, 0, n - 1, a, b) << endl;
		}
	}
	return 0;
}
