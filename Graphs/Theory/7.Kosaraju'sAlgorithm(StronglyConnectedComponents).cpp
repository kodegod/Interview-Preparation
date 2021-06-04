#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> g;
map<int,vector<int>> grev;
map<int,bool> visited;
vector<int> order;
void dfs1(int src)
{
    visited[src]=true;
    order.push_back(src);
    for(auto child:g[src])
    {
        if(!visited[child])
            dfs1(child);
    }
}
void dfs2(int src,vector<int>&ans)
{
    visited[src]=true;
    ans.push_back(src);
    for(auto child:grev[src])
    {
        if(!visited[child])
            dfs2(child,ans);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    for(int i=0; i<edges.size(); i++)
    {
        g[edges[i][0]].push_back(edges[i][1]);
        grev[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs1(i);
    int cnt=0;
    vector<vector<int>> sol;
    visited.clear();
    for(int i=0; i<n; i++)
    {
        if(!visited[order[i]])
        {
            vector<int> ans;
            dfs2(order[i],ans);
            cnt++;
            sol.push_back(ans);
        }
    }
    return sol;
}
