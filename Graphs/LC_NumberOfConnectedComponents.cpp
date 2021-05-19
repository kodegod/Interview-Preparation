//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
class Solution {
public:
    vector<int> par;
    int comp;
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
        if(rand() % 2)
            par[a]=b;
        else
            par[b]=a;
        comp--;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        par.resize(n,0);
        comp=n;
        for(int i=0; i<n; i++)
            par[i]=i;
        for(int i=0; i<edges.size(); i++)
            merge(edges[i][0],edges[i][1]);
        return comp;
    }
};
