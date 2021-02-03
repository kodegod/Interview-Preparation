#include<bits/stdc++.h>
using namespace std;

void sw(vector<int>&v,int n,int k)
{
    int csum=0;
    for(int i=0; i<k; i++)
        csum+=v[i];
    for(int i=k; i<n; i++)
    {
        cout<<csum<<" ";
        csum-=v[i-k];
        csum+=v[i];
    }
    cout<<csum;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    sw(v,n,k);
}