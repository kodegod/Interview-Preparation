// https://codeforces.com/contest/33/problem/B

// Floyd Warshall 


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
	string a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	vector<vector<int>> d(26, vector<int> (26, INT_MAX));
	for (int i = 0; i < m; i++)
	{
		char x, y;
		int c;
		cin >> x >> y >> c;
		d[x - 'a'][y - 'a'] = min(d[x - 'a'][y - 'a'], c);
	}
	for (int i = 0; i < 26; i++)
		d[i][i] = 0;
	for (int k = 0; k < 26; k++)
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	if (a.length() != b.length())
		cout << "-1";
	else
	{
		int cost = 0;
		string s;
		char letter;
		bool bar = true;
		for (int i = 0; i < a.length(); i++)
		{
			int curr_cost = INT_MAX;
			for (int j = 0; j < 26; j++)
			{
				if (d[a[i] - 'a'][j] + d[b[i] - 'a'][j] < curr_cost)
				{
					curr_cost = d[a[i] - 'a'][j] + d[b[i] - 'a'][j];
					letter = j + 97;
				}
			}
			if (curr_cost == INT_MAX)
				bar = false;
			cost += curr_cost;
			s.push_back(letter);
		}
		if (bar == false)
			cout << -1;
		else
		{
			cout << cost << endl;
			cout << s;
		}
	}
	return 0;
}
