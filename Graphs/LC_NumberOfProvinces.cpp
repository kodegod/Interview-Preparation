//https://leetcode.com/problems/number-of-provinces/
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
        if(rand() % 2==0)
            par[a]=b;
        else
            par[b]=a;
        comp--;
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        comp=n;
        par.resize(n,0);
        for(int i=0; i<n; i++)
            par[i]=i;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i; j<v.size(); j++)
            {
                if(i!=j && v[i][j]==1)
                    merge(i,j);
            }
        }
        return comp;
    }
};
