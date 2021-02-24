#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,bool> visited;
void solve(vector<vector<int>>&maze,int n,int i,int j,string&s,vector<string>&v)
{
    if(i==n-1&&j==n-1)
    {
        v.push_back(s);
        return;
    }
    visited[{i,j}]=true;
    if(j+1<n&&maze[i][j+1]==1&&visited[{i,j+1}]==false)
    {
        s.push_back('R');
        solve(maze,n,i,j+1,s,v);
        s.pop_back();
    }
    if(i+1<n&&maze[i+1][j]==1&&visited[{i+1,j}]==false)
    {
        s.push_back('D');
        solve(maze,n,i+1,j,s,v);
        s.pop_back();
    }
    if(i-1>=0&&maze[i-1][j]==1&&visited[{i-1,j}]==false)
    {
        s.push_back('U');
        solve(maze,n,i-1,j,s,v);
        s.pop_back();
    }
    if(j-1>=0&&maze[i][j-1]==1&&visited[{i,j-1}]==false)
    {
        s.push_back('L');
        solve(maze,n,i,j-1,s,v);
        s.pop_back();
    }
    visited[{i,j}]=false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> maze(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x;
                cin>>x;
                maze[i].push_back(x);
            }
        }
        vector<string> v;
        string s="";
        solve(maze,n,0,0,s,v);
        sort(v.begin(),v.end());
        if(!v.empty())
            cout<<v[0];
        for(int i=1; i<v.size(); i++)
            cout<<" "<<v[i];
        cout<<endl;
    }

}
