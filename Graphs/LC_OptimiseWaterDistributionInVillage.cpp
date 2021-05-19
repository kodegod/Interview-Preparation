//https://leetcode.com/problems/optimize-water-distribution-in-a-village/
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=0; i<wells.size(); i++)
            pipes.push_back({n+1,i+1,wells[i]});
        for(int i=0; i<pipes.size(); i++)
            edgelist.push_back({pipes[i][2],{pipes[i][0],pipes[i][1]}});
        par.resize(n+2,0);
        for(int i=1; i<=n+1; i++)
            par[i]=i;
        int cost=0;
        sort(edgelist.begin(),edgelist.end());
        for(auto it:edgelist)
        {
            int a=get_root(it.second.first);
            int b=get_root(it.second.second);
            if(a==b)
                continue;
            cost+=it.first;
            merge(it.second.first,it.second.second); 
        }
        return cost;
    }
};
