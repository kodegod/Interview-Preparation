//https://leetcode.com/problems/sliding-puzzle/

class Solution {
public:
    map<vector<vector<int>>,bool> visited;
    map<vector<vector<int>>,int> level;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        visited[board]=true;
        queue<vector<vector<int>>> q;
        q.push(board);
        level[board]=0;
        vector<vector<int>> final_board={{1,2,3},{4,5,0}};
        while(!q.empty())
        {
            vector<vector<int>> node=q.front();
            q.pop();
            if(node==final_board)
                return level[node];
            int i=0,j=0;
            bool bar=true;
            for(i=0; i<2; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(node[i][j]==0)
                    {
                        bar=false;
                        break;
                    }
                }
                if(bar==false)
                    break;
            }
            for(int k=0; k<4; k++)
            {
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x<0 || y<0 || x>=2 || y>=3)
                    continue;
                vector<vector<int>> new_board=node;
                swap(new_board[i][j],new_board[x][y]);
                if(!visited[new_board])
                {
                    visited[new_board]=true;
                    level[new_board]=level[node]+1;
                    q.push(new_board);
                }
            }
        }
        return -1;
    }
};
