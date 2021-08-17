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
    if (n % 2 == 0)
        cout << -1 << endl;
    else
    {
        vector<int> v;
        vector<int> v2;
        for (int i = 0; i < n; i++)
            v.push_back(i);
        for (int i = 1; i < n; i++)
            v2.push_back(i);
        v2.push_back(0);
        vector<int> v3;
        for (int i = 0; i < n; i++)
            v3.push_back((v[i] + v2[i]) % n);
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << v2[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << v3[i] << " ";
        cout << endl;
    }
    return 0;
}
