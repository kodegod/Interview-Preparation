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
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (v[i] > v[i + 1])
				swap(v[i], v[i + 1]);
		}
	}
	for (auto it : v)
		cout << it << " ";
}
