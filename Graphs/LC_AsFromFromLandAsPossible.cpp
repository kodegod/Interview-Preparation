//https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>,bool> visited;
    int bfs(vector<vector<int>>& grid,int&n)
    {
        queue<pair<int,int>> q,q1;
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
        int cnt=0;
        while(!q.empty())
        {
            cnt++;
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
                        q1.push({x,y});
                        visited[{x,y}]=true;
                    }
                }
            }
            swap(q,q1);
        }
        return cnt;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=bfs(grid,n);
        if(ans==1)
            return -1;
        return ans-1;
    }
};
