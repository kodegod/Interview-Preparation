//https://codeforces.com/problemset/problem/474/D
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
int dp[N];
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int t;
	cin >> t;
	int k;
	cin >> k;
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (i < k)
			dp[i] = dp[i - 1];
		else
			dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
	}
	for (int i = 1; i < N; i++)
		dp[i] += dp[i - 1];
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1] + MOD) % MOD << endl;
	}
}
