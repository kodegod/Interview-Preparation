#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    bool bar=true;
    vector<int> v;
    v.push_back(b);
    while(a!=b&&bar==true)
    {
        if(b<a)
            bar=false;
        else if(b%2==0&&b!=0)
        {
            b=b/2;
            v.push_back(b);
        }
        else if((b-1)%10==0)
        {
            b=(b-1)/10;
            v.push_back(b);
        }
        else
            bar=false;
    }
    if(bar==false)
        cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        reverse(v.begin(),v.end());
        int i=0;
        for(i=0; i<v.size()-1; i++)
            cout<<v[i]<<" ";
        cout<<v[i];
    }
}
