#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0; i<n; i++)
        cin>>v[i];
    int sufmax[n];;
    sufmax[n-1]=v[n-1];
    for(int i=n-2; i>=0; i--)
        sufmax[i]=max(sufmax[i+1],v[i]);
    int ans=INT_MIN;
    set<int> s;
    s.insert(v[0]);
    for(int i=1; i<n-1; i++)
    {
        if(sufmax[i+1]>v[i])
        {
            auto it=s.lower_bound(v[i]);
            if(it==s.begin()&&*it>v[i])
            {
                s.insert(v[i]);
                continue;
            }
            it--;
            int k=*it;
            ans=max(ans,k+v[i]+sufmax[i+1]);
        }
        s.insert(v[i]);
    }
    if(ans==INT_MIN)
        ans=0;
    cout<<ans;
}
