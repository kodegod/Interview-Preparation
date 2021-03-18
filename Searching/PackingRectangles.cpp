//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

#include<bits/stdc++.h>
using namespace std;

#define int long long


bool good(int mid, int a, int b, int n)
{
	if ((mid / a) * (mid / b) >= n)
		return true;
	return false;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int start = 0;
	int end = 1;
	while (good(end, a, b, n) == false)
		end *= 2;
	while (end > start + 1)
	{
		int mid = (start + end) / 2;
		if (good(mid, a, b, n))
			end = mid;
		else
			start = mid;
	}
	cout << end;
}
