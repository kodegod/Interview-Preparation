//

// Topological Sort

class Solution {
public:
    map<int,vector<int>> g;
    map<int,int> indegree;
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        for(int i=0; i<prereq.size(); i++)
        {
            g[prereq[i][1]].push_back(prereq[i][0]);
            indegree[prereq[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i]==0)
                q.push(i);
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            cnt++;
            q.pop();
            for(auto child:g[node])
            {
                if(--indegree[child]==0)
                    q.push(child);
            }
        }
        if(cnt==numCourses)
            return true;
        return false;
    }
};
