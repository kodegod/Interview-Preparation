#include<bits/stdc++.h>
using namespace std;

#define MOD (int)1e9+7
unsigned long long factorial(long long n)
{
	const unsigned int M = 1000000007;

	unsigned long long f = 1;
	for (int i = 1; i <= n; i++)
		f = (f * i) % M;
	return f;
}

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
		int n;
		cin >> n;
		int k = n;
		vector<int> v(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			mp[v[i]]++;
		}
		int tot = v[0];
		for (auto it : v)
			tot = tot & it;
		if (tot == 0 && mp[0] <= 1)
			cout << 0 << endl;
		else
		{
			n = mp[tot];
			int ans = ((n) * (n - 1)) % 1000000007;
			ans = ans * factorial(k - 2) % 1000000007;
			cout << ans << endl;
		}
	}
	return 0;
}
