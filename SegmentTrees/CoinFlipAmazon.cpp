#include<bits/stdc++.h>
using namespace std;

#define int long long

#define lc 2*v
#define rc 2*v+1

const int N = 200005;
int t[4 * N];

void update(int v, int tl, int tr, int pos)
{
	if (tl > pos || tr < pos)
		return;
	if (tl == tr && tr == pos)
	{
		t[v] = !t[v];
		return;
	}
	int tm = (tl + tr) / 2;
	update(lc, tl, tm, pos);
	update(rc, tm + 1, tr, pos);
	t[v] = t[lc] + t[rc];
}

void init(int v, int tl, int tr, int pos)
{
	if (pos < tl || pos > tr)
		return;
	if (tl == tr && tl == pos)
	{
		t[v] = 0;
		return;
	}
	int tm = (tl + tr) / 2;
	init(lc, tl, tm, pos);
	init(rc, tm + 1, tr, pos);
	t[v] = t[lc] + t[rc];
}

int query(int v, int tl, int tr, int L, int R)
{
	if (tl > R || tr < L )
		return 0;
	if (tl >= L && tr <= R)
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
	for (int i = 0; i < n; i++)
		init(1, 0, n - 1, i);
	for (int i = 0; i < q; i++)
	{
		int k, a, b;
		cin >> k >> a >> b;
		if (k == 0)
			update(1, 0, n - 1, a);
		else if (k == 1)
			cout << query(1, 0, n - 1, a, b) << endl;
	}
	return 0;
}
