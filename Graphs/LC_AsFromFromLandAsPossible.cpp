//https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>,bool> visited;
    void bfs(vector<vector<int>>& grid,int&n)
    {
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    visited[{i,j}]=true;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x=node.first+dir[i][0];
                int y=node.second+dir[i][1];
                if(x<0 || y<0 || x>=n || y>=n)
                    continue;
                if(!visited[{x,y}])
                {
                    grid[x][y]=1+grid[node.first][node.second];
                    q.push({x,y});
                    visited[{x,y}]=true;
                }
            }
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        bool water=false,land=false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                    water=true;
                if(grid[i][j]==1)
                    land=true;
            }
        }
        if(!water || !land)
            return -1;
        bfs(grid,n);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                ans=max(ans,grid[i][j]);
        }
        return ans-1;
    }
};
