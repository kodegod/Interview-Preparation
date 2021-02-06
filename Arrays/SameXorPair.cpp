#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i=0; i<n; i++)
        cin>>v1[i];
    for(int i=0; i<n; i++)
        cin>>v2[i];
    int x=0;
    for(int i=0; i<n; i++)
        x^=v1[i]^v2[i];
    for(int i=0; i<n; i++)
        v1[i]=v1[i]^x;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1==v2)
        cout<<"true";
    else
        cout<<"false";
}
