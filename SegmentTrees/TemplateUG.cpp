#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t[4 * N], A[N];
#define lc (v<<1)
#define rc (v<<1)|1
void update(int v, int tl, int tr, int id, int val)
{
	if (tl == id && tr == id)
	{
		t[v] = val;
		return;
	}
	if (id > tr || id < tl)
		return;
	int tm = (tl + tr) / 2;
	update(lc, tl, tm, id, val);
	update(rc, tm + 1, tr, id, val);
	t[v] = t[lc] + t[rc];
}

int query(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l)
		return 0;
	if (tl >= l && tr <= r)
		return t[v];
	int tm = (tl + tr) / 2;
	int ans = 0;
	ans += query(lc, tl, tm, l, r);
	ans += query(rc, tm + 1, tr, l, r);
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	update(1, 0, N - 1, 2, 5);
	update(1, 0, N - 1, 3, 6);
	cout << query(1, 0, N - 1, 2, 3);

}
