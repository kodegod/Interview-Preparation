//https://leetcode.com/problems/time-needed-to-inform-all-employees/
class Solution {
public:
    map<int,vector<int>> g;
    int dfs(int source,vector<int>& informTime)
    {
        int time=0;
        for(auto child:g[source])
            time=max(time,dfs(child,informTime));
        return informTime[source]+time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i=0; i<n; i++)
        {
            if(i!=headID)
                g[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }
};
