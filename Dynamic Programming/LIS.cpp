#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

int dp[10005];
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] < v[i])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}
