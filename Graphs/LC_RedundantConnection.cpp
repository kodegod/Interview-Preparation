//https://leetcode.com/problems/redundant-connection/

//DSU

class Solution {
public:
    vector<int> par;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1,0);
        for(int i=0; i<=n; i++)
            par[i]=i;
        vector<int> ans(2);
        for(int i=0; i<n; i++)
        {
            int a=get_root(edges[i][0]);
            int b=get_root(edges[i][1]);
            if(a!=b)
                merge(edges[i][0],edges[i][1]);
            else
                ans={edges[i][0],edges[i][1]};    
        }
        return ans;
    }
};
