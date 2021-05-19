//https://leetcode.com/problems/connecting-cities-with-minimum-cost/
class Solution {
public:
    vector<int> par;
    vector<pair<int,pair<int,int>>> edgelist;
    int get_root(int u)
    {
        if(par[u]==u)
            return u;
        return par[u]=get_root(par[u]);
    }
    void merge(int u,int v)
    {
        int a=get_root(u);
        int b=get_root(v);
        if(a==b)
            return;
        if(rand()%2)
            par[a]=b;
        else
            par[b]=a;
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        par.resize(n,0);
        for(int i=0; i<n; i++)
            par[i]=i;
        for(int i=0; i<connections.size(); i++)
            edgelist.push_back({connections[i][2],{connections[i][0]-1,connections[i][1]-1}});
        sort(edgelist.begin(),edgelist.end());
        int cost=0;
        int num=0;
        for(auto it:edgelist)
        {
            int a=get_root(it.second.first);
            int b=get_root(it.second.second);
            if(a==b)
                continue;
            else
            {
                cost+=it.first;
                merge(it.second.first,it.second.second);
                num++;
            }
        }
        if(num==n-1)
            return cost;
        return -1;
    }
};
