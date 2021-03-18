//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
#include<bits/stdc++.h>
using namespace std;

#define int long long

int bs(vector<int>&v, int n, int num)
{
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (v[mid] > num)
			end = mid - 1;
		else
			start = mid + 1 ;
	}
	return end;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		int ans = bs(v, n, num);
		ans++;
		cout << ans << endl;
	}
	return 0;
}
