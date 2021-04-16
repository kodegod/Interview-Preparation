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
	int w;
	cin >> w;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> we(n);
	for (int i = 0; i < n; i++)
		cin >> we[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (we[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - we[i]] + v[i]);
		}
	}
	cout << dp[n - 1][w];

}
