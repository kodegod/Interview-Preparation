//https://leetcode.com/problems/shortest-bridge/

//Multisource BFS

class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid,int i,int j,int n,queue<pair<int,int>>&q)
    {
        grid[i][j]=2;
        q.push({i,j});
        for(int k=0; k<4; k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x<0||y<0||x>=n||y>=n)
                continue;
            if(grid[x][y]==1)
                dfs(grid,x,y,n,q);
        }
    }
    int bfs(vector<vector<int>>& grid,int i,int j,int n,queue<pair<int,int>>&q)
    {
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            for(int k=0; k<4; k++)
            {
                int x=node.first+dir[k][0];
                int y=node.second+dir[k][1];
                if(x<0||y<0||x>=n||y>=n)
                    continue;
                if(grid[x][y]==0)
                {
                    q.push({x,y});
                    grid[x][y]=grid[node.first][node.second]+1;
                }
                else if(grid[x][y]==1)
                    return grid[node.first][node.second];
            }
        }
        return 0;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        bool bar=true;
        int i=0,j=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    bar=false;
                    break;
                }
            }
            if(bar==false)
                break;
        }
        dfs(grid,i,j,n,q);
        int ans=bfs(grid,i,j,n,q);
        return ans-2;
    }
};
