#include<bits/stdc++.h>
using namespace std;

int main()
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
	for (int i = 0; i < n; i++)
	{
		int miny = i;
		for (int j = i; j < n; j++)
		{
			if (v[j] < v[miny])
				miny = j;
		}
		swap(v[i], v[miny]);
	}
	for (auto it : v)
		cout << it << " ";
}
