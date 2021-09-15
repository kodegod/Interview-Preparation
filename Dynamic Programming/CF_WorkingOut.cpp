//https://codeforces.com/problemset/problem/429/B

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define MOD 1000000007
#define N 100005
#define ii pair<int,int>

int m , n;

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    vector<vector<int>> dp1(m, vector<int>(n, 0));
    vector<vector<int>> dp2(m, vector<int>(n, 0));
    vector<vector<int>> dp3(m, vector<int>(n, 0));
    vector<vector<int>> dp4(m, vector<int>(n, 0));

    dp1[0][0] = v[0][0];
    for (int i = 1; i < m; i++)
        dp1[i][0] = v[i][0] + dp1[i - 1][0];
    for (int i = 1; i < n; i++)
        dp1[0][i] = v[0][i] + dp1[0][i - 1];
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
            dp1[i][j] = v[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    }

    dp2[m - 1][0] = v[m - 1][0];
    for (int i = m - 2; i >= 0; i--)
        dp2[i][0] = v[i][0] + dp2[i + 1][0];
    for (int i = 1; i < n; i++)
        dp2[m - 1][i] = v[m - 1][i] + dp2[m - 1][i - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 1; j < n; j++)
            dp2[i][j] = v[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);
    }

    dp3[m - 1][n - 1] = v[m - 1][n - 1];
    for (int i = m - 2; i >= 0; i--)
        dp3[i][n - 1] = v[i][n - 1] + dp3[i + 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
        dp3[m - 1][i] = v[m - 1][i] + dp3[m - 1][i + 1];
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
            dp3[i][j] = v[i][j] + max(dp3[i + 1][j], dp3[i][j + 1]);
    }

    dp4[0][n - 1] = v[0][n - 1];
    for (int i = 1; i < m; i++)
        dp4[i][n - 1] = v[i][n - 1] + dp4[i - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
        dp4[0][i] = v[0][i] + dp4[0][i + 1];
    for (int i = 1; i < m; i++)
    {
        for (int j = n - 2; j >= 0; j--)
            dp4[i][j] = v[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
    }

    int ans = INT_MIN;
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int op1 = dp1[i][j - 1] + dp3[i][j + 1]; //left se aara A
            int op2 = dp1[i - 1][j] + dp3[i + 1][j]; //upar se aara A
            int op3 = dp2[i + 1][j] + dp4[i - 1][j]; //neeche se aara B
            int op4 = dp2[i][j - 1] + dp4[i][j + 1]; //left se aara B

            ans = max(ans, max(op1 + op3, op2 + op4));

        }
    }
    cout << ans;
    return 0;
}
