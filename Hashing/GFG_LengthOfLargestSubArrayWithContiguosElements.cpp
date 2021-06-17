//https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

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
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int maxy = v[i];
		int mini = v[i];
		for (int j = i + 1; j < n; j++)
		{
			maxy = max(maxy, v[j]);
			mini = min(mini, v[j]);
			if (j - i == maxy - mini)
				ans = max(ans, j - i);
		}
	}
	cout << ans + 1;
	return 0;
}
