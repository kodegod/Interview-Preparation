//https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    map<pair<int,int>,bool> visited;
    map<pair<int,int>,int> level;
    int bfs(int x,int y,vector<vector<int>>& grid,int n)
    {
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[{x,y}]=true;
        level[{x,y}]=1;
        while(!q.empty())
        {
            pair<int,int> node=q.front();
            q.pop();
            int xx=node.first;
            int yy=node.second;
            for(int i=0; i<8; i++)
            {
                int a=xx+dir[i][0];
                int b=yy+dir[i][1];
                if(a<0 || b<0 || a>=n || b>=n || grid[a][b]==1)
                    continue;
                if(level.find({a,b})!=level.end())
                    level[{a,b}]=min(level[{a,b}],level[{xx,yy}]+1);
                else
                    level[{a,b}]=level[{xx,yy}]+1;
                if(!visited[{a,b}])
                {
                    q.push({a,b});
                    visited[{a,b}]=true;
                }
            }
        }
        if(level.find({n-1,n-1})!=level.end())
            return level[{n-1,n-1}];
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
            return -1;
        return bfs(0,0,grid,n);
    }
};
