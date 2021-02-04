#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    }
    int ans=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            ans+=arr[i][j]*(i+1)*(j+1)*(n-j)*(m-i);   
    }
    cout<<ans;
}