//https://www.geeksforgeeks.org/substring-equal-number-0-1-2/

long long getSubstringWithEqual012(string str)
{
    //code here.
    int n=str.size();
    vector<int> pc0(n,0);
    vector<int> pc1(n,0);
    vector<int> pc2(n,0);
    pc0.insert(pc0.begin(),0);
    pc1.insert(pc1.begin(),0);
    pc2.insert(pc2.begin(),0);
    for(int i=1; i<=n; i++)
    {
        if(str[i-1]=='0')
        {
            pc0[i]=pc0[i-1]+1;
            pc1[i]=pc1[i-1];
            pc2[i]=pc2[i-1];
        }
        else if(str[i-1]=='1')
        {
            pc0[i]=pc0[i-1];
            pc1[i]=pc1[i-1]+1;
            pc2[i]=pc2[i-1];
        }
        else
        {
            pc0[i]=pc0[i-1];
            pc1[i]=pc1[i-1];
            pc2[i]=pc2[i-1]+1;
        }
    }
    int cnt=0;
    map<pair<int,int>,int> mp;
    mp[{0,0}]=1;
    for(int i=1; i<=n; i++)
    {
        int x=pc0[i]-pc1[i];
        int y=pc0[i]-pc2[i];
        cnt+=mp[{x,y}];
        mp[{x,y}]++;
    }
    return cnt;
}
