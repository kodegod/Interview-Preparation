//https://leetcode.com/problems/the-maze/

// BFS (Good Q)


class Solution {
public:
    map<pair<int,int>,bool> visited;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        visited[{start[0],start[1]}]=true;
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            if(curr.first==destination[0] && curr.second==destination[1])
                return true;
            for(int i=0; i<4; i++)
            {
                int x=curr.first+dir[i][0];
                int y=curr.second+dir[i][1];
                if(x<0||y<0||x>=m||y>=n||maze[x][y]==1)
                    continue;
                while(maze[x][y]==0)
                {
                    x+=dir[i][0];
                    y+=dir[i][1];
                    if(x<0||y<0||x>=m||y>=n||maze[x][y]==1)
                        break;
                }
                x-=dir[i][0];
                y-=dir[i][1];
                if(visited[{x,y}]==false)
                {
                    q.push({x,y});
                    visited[{x,y}]=true;
                }
            }
        }
        return false;
    }
};
