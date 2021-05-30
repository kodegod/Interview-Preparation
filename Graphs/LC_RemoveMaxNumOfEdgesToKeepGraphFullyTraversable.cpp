//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

// DSU

class Solution {
public:
    vector<int> par1,par2;
    int comp1,comp2;
    int get_root1(int u)
    {
        if(par1[u]==u)
            return u;
        return par1[u]=get_root1(par1[u]);
    }
    void merge1(int u,int v)
    {
        int a=get_root1(u);
        int b=get_root1(v);
        if(a==b)
            return;
        if(rand()&2)
            par1[a]=b;
        else
            par1[b]=a;
        comp1--;
    }
    int get_root2(int u)
    {
        if(par2[u]==u)
            return u;
        return par2[u]=get_root2(par2[u]);
    }
    void merge2(int u,int v)
    {
        int a=get_root2(u);
        int b=get_root2(v);
        if(a==b)
            return;
        if(rand()&2)
            par2[a]=b;
        else
            par2[b]=a;
        comp2--;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        par1.resize(n+1,0);
        par2.resize(n+1,0);
        comp1=n;
        comp2=n;
        for(int i=1; i<=n; i++)
        {
            par1[i]=i;
            par2[i]=i;
        }
        int ans=0;
        for(int i=0; i<edges.size(); i++)
        {
            if(edges[i][0]==3)
            {
                int a1=get_root1(edges[i][1]);
                int b1=get_root1(edges[i][2]);
                int a2=get_root2(edges[i][1]);
                int b2=get_root2(edges[i][2]);
                if(a1==b1 && a2==b2)
                {
                    ans++;
                    continue;
                }
                merge1(edges[i][1],edges[i][2]);
                merge2(edges[i][1],edges[i][2]);
            }
        }
        for(int i=0; i<edges.size(); i++)
        {
            if(edges[i][0]==1)
            {
                int a=get_root1(edges[i][1]);
                int b=get_root1(edges[i][2]);
                if(a==b)
                {
                    ans++;
                    continue;
                }
                else
                    merge1(edges[i][1],edges[i][2]);
            }
            else if(edges[i][0]==2)
            {
                int a=get_root2(edges[i][1]);
                int b=get_root2(edges[i][2]);
                if(a==b)
                {
                    ans++;
                    continue;
                }
                else
                    merge2(edges[i][1],edges[i][2]);
            }
        }
        if(comp1==1 && comp2==1)
            return ans;
        return -1;
    }
};
