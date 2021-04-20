#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
int dp[21];
int cs(vector<int>&arr, int n) {
	// write your code here
	dp[0] = 1;
	for (int i = 0; i < 21; i++)
	{
		while (arr[i])
		{
			dp[arr[i] + i] += dp[i];
			arr[i]--;
		}
	}
	return dp[n];
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 0; i <= n; i++)
		cin >> arr[i];
	cout << cs(arr, n);
}
