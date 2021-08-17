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
    int k1;
    cin >> k1;
    vector<int> v1(k1);
    for (int i = 0; i < k1; i++)
        cin >> v1[i];
    int k2;
    cin >> k2;
    vector<int> v2(k2);
    for (int i = 0; i < k2; i++)
        cin >> v2[i];
    map < pair<vector<int>, vector<int>>, bool> vis;
    vis[ {v1, v2}] = true;
    bool bar = true;
    int cnt = 0;
    while (v1.size() > 0 && v2.size() > 0)
    {
        cnt++;
        if (v1[0] > v2[0])
        {
            v1.push_back(v2[0]);
            v1.push_back(v1[0]);
            v1.erase(v1.begin());
            v2.erase(v2.begin());
        }
        else
        {
            v2.push_back(v1[0]);
            v2.push_back(v2[0]);
            v2.erase(v2.begin());
            v1.erase(v1.begin());
        }
        if (vis.find({v1, v2}) != vis.end())
        {
            bar = false;
            break;
        }
        else
            vis[ {v1, v2}] = true;
    }
    if (bar == false)
        cout << -1;
    else
    {
        cout << cnt << " ";
        if (v1.size() == 0)
            cout << 2;
        else
            cout << 1;
    }
    return 0;
}
