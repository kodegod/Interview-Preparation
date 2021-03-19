#include<bits/stdc++.h>
using namespace std;

#define int long long

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
	int lo = 0;
	int mid = 0;
	int hi = n - 1;
	while (mid <= hi)
	{
		if (v[mid] == 0)
		{
			swap(v[mid], v[lo]);
			lo++;
			mid++;
		}
		else if (v[mid] == 1)
			mid++;
		else
		{
			swap(v[mid], v[hi]);
			hi--;
		}
	}
	for (auto it : v)
		cout << it << " ";
}
