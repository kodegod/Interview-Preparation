//https://leetcode.com/problems/redundant-connection-ii/

class Solution {
public:
    vector<int> par,indegree;
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
            int n=edges.size();
            int blacklist=-1;
            indegree.resize(n+1,-1);
            par.resize(n+1,0);
            for(int i=1; i<=n; i++)
                par[i]=i;
            for(int i=0; i<n; i++)
            {
                if(indegree[edges[i][1]]!=-1)
                    blacklist=i;
                indegree[edges[i][1]]=i;
            }
            bool cycle=false;
            for(int i=0; i<n; i++)
            {
                if(i==blacklist)
                    continue;
                int a=get_root(edges[i][0]);
                int b=get_root(edges[i][1]);
                if(a==b)
                {
                    if(blacklist==-1)
                        return edges[i];
                    cycle=true;
                    break;
                }
                merge(a,b);
            }
            if(cycle==false)
                return edges[blacklist];
            for(int i=0; i<n; i++)
            {
                if(i==blacklist)
                    continue;
                if(edges[i][1]==edges[blacklist][1])
                    return edges[i];
            }
        return {};
    }
};
