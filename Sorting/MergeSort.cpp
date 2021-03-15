#include<bits/stdc++.h>
using namespace std;

#define int long long

#define lc 2*v
#define rc 2*v+1

const int N = 200005;
string t[4 * N];

void merge(vector<int>&v, int l1, int r1, int l2, int r2)
{
	int i = l1;
	int j = l2;
	int k = 0;
	vector<int> c(r1 - l1 + 1 + r2 - l2 + 1);
	while (i <= r1 && j <= r2)
	{
		if (v[i] <= v[j])
			c[k++] = v[i++];
		else
			c[k++] = v[j++];
	}
	while (i <= r1)
		c[k++] = v[i++];
	while (j <= r2)
		c[k++] = v[j++];
	int l = 0;
	for (int i = l1; i <= r2; i++)
		v[i] = c[l++];
}

void mergeSort(vector<int>&v, int n, int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) / 2;
	mergeSort(v, n, l , mid);
	mergeSort(v, n, mid + 1, r);
	merge(v, l, mid, mid + 1, r);
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	mergeSort(v, n, 0, n - 1);
	for (auto it : v)
		cout << it << " ";
}
