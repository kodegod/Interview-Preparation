//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
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
        if(rand()%2)
            par[a]=b;
        else
            par[b]=a;
        comp--;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        comp=n;
        par.resize(n,0);
        for(int i=0; i<n; i++)
            par[i]=i;
        for(int i=0; i<m; i++)
            merge(connections[i][0],connections[i][1]);
        int needed=comp-1;
        if(n-m>1)
            return -1;
        return needed;
    }
};
