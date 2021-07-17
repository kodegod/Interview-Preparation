//

// Very Good Q 

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int dp[200005][10];

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    int i = 0;
    for (int j = 0; j < 10; j++)
        dp[i][j] = 1;
    for (i = 1; i < 200005; i++)
    {
        for (int j = 0; j < 9; j++)
            dp[i][j] = dp[i - 1][j + 1] % 1000000007;
        dp[i][9] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        while (n > 0)
        {
            int curr = n % 10;
            ans += dp[m][curr] % 1000000007;
            ans = ans % 1000000007;
            n /= 10;
        }
        cout << ans % 1000000007 << endl;
    }
    return 0;
}
