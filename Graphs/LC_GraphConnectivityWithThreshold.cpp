//https://leetcode.com/problems/graph-connectivity-with-threshold/

// DSU


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
            par[b]=a;
        else
            par[a]=b;
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        par.resize(n+1,0);
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=threshold+1; i<=(n/2); i++)
        {
            for(int j=2*i; j<=n; j+=i)
                merge(i,j);
        }
        vector<bool> v;
        for(int i=0; i<queries.size(); i++)
        {
            int a=get_root(queries[i][0]);
            int b=get_root(queries[i][1]);
            if(a==b)
                v.push_back(true);
            else
                v.push_back(false);
        }
        return v;
    }
};
