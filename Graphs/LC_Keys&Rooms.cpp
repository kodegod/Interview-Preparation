//https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    map<int,vector<int>> g;
    map<int,bool> visited;
    void dfs(int src,vector<vector<int>>& rooms)
    {
        visited[src]=true;
        for(auto child:g[src])
        {
            if(!visited[child])
                dfs(child,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<rooms[i].size(); j++)
                g[i].push_back(rooms[i][j]);
        }
        dfs(0,rooms);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<rooms[i].size(); j++)
                if(!visited[rooms[i][j]])
                    return false;
        }
        return true;
    }
};
