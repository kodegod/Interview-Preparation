//https://codeforces.com/contest/1513/problem/A
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		if (k > ((n + 1) / 2 - 1))
		{
			cout << -1 << endl;
			continue;
		}
		int cnt = 0;
		vector<int> v;
		for (int i = 0; i < n; i++)
			v.push_back(i + 1);
		vector<int> v2 = v;
		reverse(v2.begin(), v2.end());
		vector<int> ans;
		bool bar = true;
		for (int i = 0; i < n ; i ++)
		{
			if (bar == true)
			{
				ans.push_back(v[0]);
				v.erase(v.begin());
				if (cnt != k)
					bar = false;
			}
			else
			{
				ans.push_back(v2[0]);
				v2.erase(v2.begin());
				bar = true;
				cnt++;
			}
		}
		for (auto it : ans)
			cout << it << " ";
		cout << endl;
 
	}
	return 0;
}
