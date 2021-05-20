//https://leetcode.com/problems/01-matrix/
class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>,bool> visited;
    void bfs(vector<vector<int>>& mat,int&m,int&n)
    {
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
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
                if(x<0 || y<0 || x>=m || y>=n)
                    continue;
                if(!visited[{x,y}])
                {
                    q.push({x,y});
                    mat[x][y]=1+mat[node.first][node.second];
                    visited[{x,y}]=true;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        bfs(mat,m,n);
        return mat;
    }
};
