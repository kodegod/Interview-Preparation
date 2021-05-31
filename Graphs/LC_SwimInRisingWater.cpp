//https://leetcode.com/problems/swim-in-rising-water/

// Dijkstra on Matrix


class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        map<int,bool> visited;
        visited[grid[0][0]]=true;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> node=pq.top();
            pq.pop();
            if(node.second.first==n-1 && node.second.second == n-1)
                return node.first;
            for(int i=0; i<4; i++)
            {
                int x=node.second.first+dir[i][0];
                int y=node.second.second+dir[i][1];
                if(x<0||y<0||x>=n||y>=n||visited[grid[x][y]]==true)
                    continue;
                pq.push({max(node.first,grid[x][y]),{x,y}});
                visited[grid[x][y]]=true;
            }
        }
        return 0;
    }
};


// MST - Kruskal

class Solution {
public:
    vector<int> par;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int get_root(int u)
    {
        if(u==par[u])
            return u;
        return par[u]=get_root(par[u]);
    }
    void merge(int u,int v){
        int a=get_root(u);
        int b=get_root(v);
        if(a==b)
            return;
        if(rand()%2)
            par[a]=b;
        else
            par[b]=a;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        par.resize(n*n,0);
        for(int i=0; i<par.size(); i++)
            par[i]=i;
        vector<pair<int,pair<int,int>>> edgelist;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<4; k++)
                {
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(x<0||y<0||x>=n||y>=n)
                        continue;
                    edgelist.push_back({max(grid[x][y],grid[i][j]),{grid[i][j],grid[x][y]}});
                }
            }
        }
        int ans=0;
        sort(edgelist.begin(),edgelist.end());
        for(auto it:edgelist)
        {
            int x=get_root(it.second.first);
            int y=get_root(it.second.second);
            if(x==y)
                continue;
            else
            {
                merge(it.second.first,it.second.second);
                int a=get_root(grid[0][0]);
                int b=get_root(grid[n-1][n-1]);
                if(a==b)
                    return it.first;
            }
        }
        return 0;
    }
};


