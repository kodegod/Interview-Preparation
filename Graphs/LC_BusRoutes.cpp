//https://leetcode.com/problems/bus-routes/


// BFS++


class Solution {
public:
    map<int,vector<int>> busstop;
    map<int,vector<int>> bus;
    map<int,bool> visbus;
    map<int,bool> visbusstop;
    int bfs(int source,int target)
    {
        queue<pair<int,int>> q;
        q.push({source,0});
        visbus[source]=true;
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            for(auto it:bus[curr.first])
            {
                if(!visbusstop[it])
                {
                    visbusstop[it]=true;
                    for(auto ip:busstop[it])
                    {
                        if(!visbus[ip])
                        {
                            q.push({ip,curr.second+1});
                            visbus[ip]=true;
                            if(ip==target)
                                return curr.second+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)
            return 0;
        for(int i=0; i<routes.size(); i++)
        {
            for(int j=0; j<routes[i].size(); j++)
            {
                busstop[i].push_back(routes[i][j]);
            }
        }
        for(auto it:busstop)
        {
            for(auto ip:it.second)
                bus[ip].push_back(it.first);
        }
        return bfs(source,target);
    }
};
