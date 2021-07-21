//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/the-colorful-street-1/

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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0][0] = v[0][0];
        dp[0][1] = v[0][1];
        dp[0][2] = v[0][2];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = v[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = v[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = v[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
        }
        cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
    }
    return 0;
}
