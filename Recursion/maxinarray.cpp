#include<bits/stdc++.h>
using namespace std;

int maxy(vector<int>&v,int l,int r)
{
    if(l==r)
        return v[l];
    int mid=(l+r)/2;
    return max(maxy(v,l,mid),maxy(v,mid+1,r));
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<maxy(v,0,n-1);
}
