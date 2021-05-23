class Solution {
public:
    map<int,vector<int>> g;
    vector<int> par,low,disc;
    vector<vector<int>> bridges;
    int time=0;
    void AP(int src)
    {
        low[src]=disc[src]=++time;
        for(auto it:g[src])
        {
            if(it==par[src])
                continue;
            if(disc[it]!=0)
                low[src]=min(low[src],disc[it]);
            else
            {
                par[it]=src;
                AP(it);
                if(low[it]>disc[src]) // for Articulation point just add >= and also check the case for the original source node separately
                    bridges.push_back({src,it});
                low[src]=min(low[src],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0; i<connections.size(); i++)
        {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        par.resize(n,0);
        low.resize(n,0);
        disc.resize(n,0);
        for(int i=0; i<n; i++)
            par[i]=i;
        AP(0);
        return bridges;
    }
};
