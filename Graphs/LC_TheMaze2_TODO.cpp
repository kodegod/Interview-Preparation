//https://leetcode.com/problems/the-maze-ii/

// BFS (Very good Q)

class Solution {
public:
    map<pair<int,int>,int> level;
    map<pair<int,int>,bool> visited;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        visited[{start[0],start[1]}]=true;
        level[{start[0],start[1]}]=0;
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x=curr.first+dir[i][0];
                int y=curr.second+dir[i][1];
                if(x<0||y<0||x>=m||y>=n||maze[x][y]==1)
                    continue;
                int cnt=0;
                while(maze[x][y]==0)
                {
                    cnt++;
                    x+=dir[i][0];
                    y+=dir[i][1];
                    if(x<0||y<0||x>=m||y>=n||maze[x][y]==1)
                        break;
                }
                x-=dir[i][0];
                y-=dir[i][1];
                if(visited[{x,y}]==false)
                {
                    level[{x,y}]=level[curr]+cnt;
                    q.push({x,y});
                    visited[{x,y}]=true;
                }
                else if(level[{x,y}]>level[curr]+cnt)
                {
                    level[{x,y}]=level[curr]+cnt;
                    q.push({x,y});
                }
            }
        }
        if(level.find({destination[0],destination[1]})!=level.end())
            return level[{destination[0],destination[1]}];
        return -1;
    }
};
