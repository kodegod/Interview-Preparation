//https://leetcode.com/problems/shortest-path-to-get-food/

// BFS

class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>,bool> visited;
    map<pair<int,int>,int> level;
    int bfs(int i,int j,vector<vector<char>>& grid,int &m,int &n)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[{i,j}]=true;
        level[{i,j}]=0;
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            for(int k=0; k<4; k++)
            {
                int x=node.first+dir[k][0];
                int y=node.second+dir[k][1];
                if(x<0||y<0||x>=m||y>=n||visited[{x,y}]==true)
                    continue;
                if(grid[x][y]=='#')
                    return level[node]+1;
                if(grid[x][y]!='O')
                    continue;
                visited[{x,y}]=true;
                level[{x,y}]=level[node]+1;
                q.push({x,y});
            }
        }
        return -1;
    }
    int getFood(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='*')
                    return bfs(i,j,grid,m,n);
            }
        }
        return -1;
    }
};
