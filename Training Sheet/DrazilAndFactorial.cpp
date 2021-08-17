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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' || s[i] == '1')
        {
            cnt++;
            s.erase(s.begin() + i);
            i--;
        }
    }
    int i = 0;
    int count = 0 ;
    while (i < n)
    {
        if (s[i] == '4')
        {
            s.erase(s.begin() + i);
            s = s + "322";
            count++;
            i--;
        }
        else if (s[i] == '6')
        {
            s.erase(s.begin() + i);
            s = s + "53";
            count++;
            i--;
        }
        else if (s[i] == '8')
        {
            s.erase(s.begin() + i);
            s = s + "7222";
            count++;
            i--;
        }
        else if (s[i] == '9')
        {
            s.erase(s.begin() + i);
            s = s + "7332";
            count++;
            i--;
        }
        i++;
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}
