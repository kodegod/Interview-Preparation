//https://leetcode.com/problems/number-of-enclaves/
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<int>>& grid,int&m,int&n)
    {
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=0;
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
                if(x<0 || y<0 || x>=m || y>=n)
                    continue;
                if(grid[x][y]==1)
                {
                    q.push({x,y});
                    grid[x][y]=0;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ones=0;
        bfs(grid,m,n);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                if(grid[i][j]==1)
                    ones++;
        }
        return ones;
    }
};
