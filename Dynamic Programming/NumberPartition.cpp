
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

int dp[1005][1005];
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - j][j] + dp[i][j + 1];
		}
	}
	cout << dp[4][1];
	return 0;
}
